#include "print_object.h"
#include <stdio.h>
#include "libft.h"
#include "token.h"
#include "array.h"
#include "camera.h"

static void print_token_type(int type)
{
	if(type == identifier)
		printf("identifier");
	if(type == pos_int)
		printf("pos_int");
	if(type == neg_int)
		printf("neg_int");
	if(type == pos_double)
		printf("pos_double");
	if(type == neg_double)
		printf("neg_double");
	if(type == separator_value)
		printf("separator_value");
	if(type == separator_property)
		printf("separator_property");
	if(type == eol)
		printf("eol");
}

void print_matrix(t_matrix *to_print, int detalhed)
{

	int last_col = to_print->cols - 1;
	int matrix_size = to_print->rows * to_print->cols;

	printf("rows: %d, cols: %d\n", to_print->rows, to_print->cols);
	for (int count = 0; count < matrix_size; count++)
	{
		double element = to_print->elements[count];
		if (detalhed)
			printf("%100.90f", element);
		else
			printf("%10.5f", element);

		if ((count % to_print->cols) == last_col)
			printf("\n");
		else
			printf(" | ");
	}
}

void print_color(t_color *color)
{
	if (!color)
	{
		printf("color == NULL");
		return ;
	}
	printf("color: red:%f, green:%f, blue:%f\n", color->red, color->green, color->blue);
}

void print_list_token(t_list *list)
{
	size_t	size_list;

	if (!list)
	{
		printf("list == NULL");
		return ;
	}
	size_list = ft_lstsize(list);
	printf("token list: [");
	for(unsigned int count=0; count < size_list; count++)
	{
		t_token *token = (t_token *) ft_lstget(list, count)->content;
		printf("[text: \"%s\", type: ", token->text);
		print_token_type(token->type);
		printf("]");
	}
	printf("]\n");
}

void print_camera(t_camera *camera)
{
	printf("hsize=%d, vsize=%d, half_view=%f, fov=%f, pixel_size=%f, half_width=%f, half_height=%f\n",
			camera->hsize,
			camera->vsize,
			camera->half_view,
			camera->field_of_view,
			camera->pixel_size,
			camera->half_width,
			camera->half_height);
	print_matrix(camera->transformation, 0);
}