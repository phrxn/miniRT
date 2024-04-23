/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:04:27 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/04/22 13:31:25 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_operations.h"
#include "matrix.h"
#include <math.h>

static int	matrix_is_vector(t_matrix *a)
{
	if (a->rows != 4 || a->cols != 1 || a->elements[W] != VECTOR)
		return (ERR_NOT_VECTOR);
	return (OK_OPERATION);
}

double	matrix_get_magnitude(t_matrix *a)
{
	double	magnitude;
	double	x;
	double	y;
	double	z;
	double	w;

	x = a->elements[X];
	y = a->elements[Y];
	z = a->elements[Z];
	w = a->elements[W];
	magnitude = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2));
	return (magnitude);
}

int	matrix_normalization(t_matrix *a, t_matrix *unit)
{
	double	magnitude;

	if (matrix_is_vector(a))
		return (ERR_NOT_VECTOR);
	magnitude = matrix_get_magnitude(a);
	if (magnitude == 0)
		return (ERR_MAGNITUDE_ZERO);
	unit->elements[X] = a->elements[X] / magnitude;
	unit->elements[Y] = a->elements[Y] / magnitude;
	unit->elements[Z] = a->elements[Z] / magnitude;
	unit->elements[W] = a->elements[W] / magnitude;
	return (OK_OPERATION);
}

int	matrix_dot(t_matrix *a, t_matrix *b, double *c)
{
	int	count;
	int	matrix_size;

	count = 0;
	matrix_size = a->rows * a->cols;
	*c = 0;
	if (matrix_is_vector(a) || matrix_is_vector(b))
		return (ERR_NOT_VECTOR);
	while (count < matrix_size)
	{
		*c += a->elements[count] * b->elements[count];
		count++;
	}
	return (OK_OPERATION);
}

int	matrix_cross(t_matrix *a, t_matrix *b, t_matrix *c)
{
	double	x;
	double	y;
	double	z;

	if (matrix_is_vector(a) || matrix_is_vector(b))
		return (ERR_NOT_VECTOR);
	c->elements[X] = a->elements[Y] * b->elements[Z] \
				- a->elements[Z] * b->elements[Y];
	c->elements[Y] = a->elements[Z] * b->elements[X] \
				- a->elements[X] * b->elements[Z];
	c->elements[Z] = a->elements[X] * b->elements[Y] \
				- a->elements[Y] * b->elements[X];
	c->elements[W] = VECTOR;
	return (OK_OPERATION);
}
