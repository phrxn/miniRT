/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:02:02 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/06 20:01:37 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_alloc.h"
#include "matrix.h"
#include "matrix_operations.h"
#include "matrix_fill.h"
#include "messages.h"
#include "matrix_errors.h"
#include <stdlib.h>

t_matrix	*matrix_create_point(double x, double y, double z)
{
	t_matrix	*new_point;

	new_point = create_matrix(4, 1);
	if (!new_point)
		return (new_point);
	new_point->elements[X] = x;
	new_point->elements[Y] = y;
	new_point->elements[Z] = z;
	new_point->elements[W] = POINT;
	return (new_point);
}

t_matrix	*matrix_create_vector(double x, double y, double z)
{
	t_matrix	*new_vector;

	new_vector = create_matrix(4, 1);
	if (!new_vector)
		return (new_vector);
	new_vector->elements[X] = x;
	new_vector->elements[Y] = y;
	new_vector->elements[Z] = z;
	new_vector->elements[W] = VECTOR;
	return (new_vector);
}

t_matrix	*matrix_create_identity_4x4(void)
{
	t_matrix	*new_identity;

	new_identity = create_matrix(4, 4);
	if (!new_identity)
		return (new_identity);
	matrix_fill_identity(new_identity);
	return (new_identity);
}

t_matrix	*matrix_create_inverse(t_matrix *matrix_to_invert)
{
	int			return_code;
	t_matrix	*new_inverse;

	new_inverse = create_matrix(4, 4);
	if (!new_inverse)
		return (new_inverse);
	return_code = matrix_inverse_4x4(matrix_to_invert, new_inverse);
	if (return_code != OK_OPERATION)
	{
		show_error_matrix("matrix_create_inverse", return_code);
		destroy_matrix(&new_inverse);
	}
	return (new_inverse);
}

t_matrix	*matrix_create_mult(t_matrix *a, t_matrix *b)
{
	int			return_code;
	t_matrix	*new_matrix_mul;

	new_matrix_mul = create_matrix(a->rows, b->cols);
	if (!new_matrix_mul)
		return (new_matrix_mul);
	return_code = matrix_mult(a, b, new_matrix_mul);
	if (return_code != OK_OPERATION)
	{
		show_error_matrix("matrix_create_mult", return_code);
		destroy_matrix(&new_matrix_mul);
	}
	return (new_matrix_mul);
}
