#include "compare.h"
#include "matrix.h"
#include "color.h"
#include <math.h>

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
