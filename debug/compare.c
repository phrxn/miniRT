#include "compare.h"

#include "color.h"
#include "token.h"
#include <math.h>
#include "shape.h"
#include "matrix.h"

#include <string.h>
#include <stdlib.h>

static int compare_string(char *a, char *b)
{
	if (!a && b)
		return 1;
	if (a && !b)
		return 1;
	if (!a && !b)
		return 0;
	return strcmp(a, b);
}

int compare_double(double a, double b)
{
	return (fabs(a - b) > EPSILON);
}

/// @brief
/// @param a
/// @param b
/// @return 0 if equal, 1 otherwise
int	compare_matrix(t_matrix *a, t_matrix *b)
{
	if (a->rows != b->rows)
		return (1);
	if (a->cols != b->cols)
		return (1);
	int	size = a->rows * a->cols;
	for (int i = 0; i < size; i++)
	{
		if (compare_double(a->elements[i], b->elements[i]))
			return(1);
	}
	return(0);
}

int	compare_color(t_color *a, t_color *b)
{
	if (compare_double(a->red, b->red))
		return 1;
	if (compare_double(a->green, b->green))
		return 1;
	if (compare_double(a->blue, b->blue))
		return 1;
	return 0;
}

int compare_material(t_material *a, t_material *b)
{
	if (compare_color(&a->color, &b->color))
		return 1;
	if (a->ambient != b->ambient)
		return 1;
	if (a->diffuse != b->diffuse)
		return 1;
	if (a->shininess != b->shininess)
		return 1;
	if (a->specular != b->specular)
		return 1;
	return 0;
}

int	compare_shape(t_shape *a, t_shape *b)
{
	if (a->id != b->id)
		return 1;
	if (a->type != b->type)
		return 1;
	if (compare_matrix(a->transformation, b->transformation))
		return 1;
	if (compare_material(&a->material, &b->material))
		return 1;
	if (a->type == TYPE_SPHERE)
		return compare_sphere(a->shape, b->shape);
	return 1;
}

int compare_sphere(t_sphere *a, t_sphere *b)
{
	if (compare_matrix(a->center, b->center))
		return 1;
	return (a->radius != b->radius);
}

int	compare_token(t_token *a, t_token *b)
{
	if (!a && b)
		return 1;
	if (a && !b)
		return 1;
	if(a->type != b->type)
		return 1;
	return compare_string(a->text, b->text);
}