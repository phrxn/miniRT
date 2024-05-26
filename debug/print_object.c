#include "print_object.h"
#include <stdio.h>
#include "libft.h"
#include "token.h"
#include "array.h"
#include "camera.h"
#include "array.h"
#include "line.h"
#include "world.h"
#include "light.h"

static char *tokens_type_string[8] =
{
	"identifier",
	"pos_int",
	"neg_int",
	"pos_double",
	"neg_double",
	"separator_value",
	"separator_property",
	"eol"
};

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


// =========================== list lines print

static char *print_token_type(t_token_type type)
{
	return tokens_type_string[type - 1];
}

void print_token_list(t_list *list, int print_new_line)
{
	size_t	size_list;

	if (!list)
	{
		printf("[list == NULL]");
		return ;
	}
	size_list = ft_lstsize(list);
	printf("token list: [");
	for(unsigned int count=0; count < size_list; count++)
	{
		t_token *token = (t_token *) ft_lstget(list, count)->content;
		printf("[type: %s, text: \"%s\"]", print_token_type(token->type), token->text);
		if ((size_list - count) > 1)
			printf(",");
	}
	printf("]");
	if (print_new_line)
		printf("\n");
}


static void print_line(t_line *line)
{
	printf("{number: %d, ", line->line_number);
	print_token_list(line->token_list, 0);
	printf("}");
}

void print_line_list(t_list *line_list)
{
	if (line_list == NULL)
	{
		printf("line_list == NULL");
		return ;
	}
	size_t	list_size = ft_lstsize(line_list);

	printf("line_list(");
	for(size_t count = 0; count < list_size; count++)
	{
		t_line *tmp_line = (t_line*) ft_lstget(line_list, count)->content;
		print_line(tmp_line);
		if (list_size - count > 1)
			printf(",");
	}
	printf(")\n");
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

//================= print world ===========================


static void	print_world_ambient(const t_world *world)
{
	if (!world->ambient)
	{
		printf("ambient: NULL\n");
		return ;
	}
	printf("ambient: radio:%f, [color: red:%f, green:%f, blue:%f]\n",
		world->ambient->radio,
		world->ambient->color.red,
		world->ambient->color.green,
		world->ambient->color.blue
	);
}

static void	print_world_camera(const t_world *world)
{
	t_camera *camera;
	if (!world->camera)
		return ;
	camera = world->camera;
	printf("camera: hsize=%d, vsize=%d, half_view=%f, fov=%f, pixel_size=%f, half_width=%f, half_height=%f\n",
			camera->hsize,
			camera->vsize,
			camera->half_view,
			camera->field_of_view,
			camera->pixel_size,
			camera->half_width,
			camera->half_height);
	printf("transformation matrix: ");
	print_matrix(camera->transformation, 0);
	printf("transformation matrix inverted: ");
	print_matrix(camera->transformation_inv, 0);
}

static void print_world_color(t_color *color)
{
	printf("[color[red:%f, green:%f, blue:%f]]", color->red, color->green, color->blue);
}

static void print_world_coordanates(t_matrix *coor)
{
	printf("[coor[x=%f, y=%f, z=%f]]", coor->elements[X], coor->elements[Y],coor->elements[Z]);
}

static void print_world_light(const t_world *world)
{
	if (!world->lights)
	{
		printf("ligths == NULL\n");
		return ;
	}
	t_uint	size_list = ft_lstsize(world->lights);
	printf("lights: [");
	for(t_uint count = 0; count < size_list; count++)
	{
		t_light *temp_light = (t_light *)ft_lstget(world->lights, count)->content;
		printf("[light: ");
		print_world_coordanates(temp_light->position);
		printf(", ");
		print_world_color(&(temp_light->intensity));
		printf("]");
		if (size_list - 1 > count)
			printf(",");
	}
	printf("]\n");
}

void	print_world_shapes(const t_world *world)
{
	t_list	*list_shapes = world->shapes;
	//t_shape	*tmp_shape;

	if (!list_shapes)
	{
		printf("shapes == NULL");
		return ;
	}
	t_uint	size_list = ft_lstsize(world->shapes);
	printf("shapes: [");
	for(t_uint count = 0; count < size_list; count++)
	{
		t_shape *line = (t_shape *)ft_lstget(list_shapes, count)->content;
		printf("shape type: %d", line->type);
		if (size_list - count > 1)
			printf(", ");
	}
	printf("]\n");
}

void	print_world(const t_world *world)
{
	printf("world:\n");
	print_world_ambient(world);
	print_world_camera(world);
	print_world_light(world);
	print_world_shapes(world);
}