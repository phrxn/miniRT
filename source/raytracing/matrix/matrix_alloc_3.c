/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_alloc_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:02:02 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/06 19:41:29 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_alloc.h"
#include "matrix.h"
#include "matrix_operations.h"
#include "matrix_fill.h"
#include "messages.h"
#include "matrix_errors.h"
#include <stdlib.h>

t_matrix	*matrix_create_shearing(t_shearing *shearing)
{
	t_matrix	*new_matrix;

	new_matrix = create_matrix(4, 4);
	if (!new_matrix)
		return (new_matrix);
	matrix_fill_shearing(new_matrix, shearing);
	return (new_matrix);
}

t_matrix	*matrix_create_subtraction(t_matrix *a, t_matrix *b)
{
	int			return_code;
	t_matrix	*new_matrix;

	new_matrix = create_matrix(a->rows, a->cols);
	if (!new_matrix)
		return (new_matrix);
	return_code = matrix_subtraction(a, b, new_matrix);
	if (return_code != OK_OPERATION)
	{
		show_error_matrix("matrix_create_subtraction", return_code);
		destroy_matrix(&new_matrix);
	}
	return (new_matrix);
}

t_matrix	*matrix_create_transpose(t_matrix *a)
{
	int			return_code;
	t_matrix	*new_matrix;

	new_matrix = create_matrix(a->rows, a->cols);
	if (!new_matrix)
		return (new_matrix);
	return_code = matrix_transpose(a, new_matrix);
	if (return_code != OK_OPERATION)
	{
		show_error_matrix("matrix_create_transpose", return_code);
		destroy_matrix(&new_matrix);
	}
	return (new_matrix);
}
