/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:56:46 by gacalaza          #+#    #+#             */
/*   Updated: 2024/04/20 18:24:31 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_fill.h"
#include "matrix.h"
#include "types.h"
#include <math.h>

void	matrix_fill_zero(t_matrix *matrix)
{
	t_uint	count;
	t_uint	size;

	count = 0;
	size = matrix->rows * matrix->cols;
	while (count < size)
	{
		matrix->elements[count] = 0;
		count++;
	}
}

void	matrix_fill_identity(t_matrix *matrix)
{
	set_element(matrix, 0, 0, 1);
	set_element(matrix, 1, 1, 1);
	set_element(matrix, 2, 2, 1);
	set_element(matrix, 3, 3, 1);
}

void	matrix_fill_rot_x(t_matrix *matrix, double radian)
{
	matrix_fill_zero(matrix);
	matrix_fill_identity(matrix);
	set_element(matrix, 1, 1, cos(radian));
	set_element(matrix, 1, 2, -sin(radian));
	set_element(matrix, 2, 1, sin(radian));
	set_element(matrix, 2, 2, cos(radian));
}

void	matrix_fill_rot_y(t_matrix *matrix, double radian)
{
	matrix_fill_zero(matrix);
	matrix_fill_identity(matrix);
	set_element(matrix, 0, 0, cos(radian));
	set_element(matrix, 0, 2, sin(radian));
	set_element(matrix, 2, 0, -sin(radian));
	set_element(matrix, 2, 2, cos(radian));
}

void	matrix_fill_rot_z(t_matrix *matrix, double radian)
{
	matrix_fill_zero(matrix);
	matrix_fill_identity(matrix);
	set_element(matrix, 0, 0, cos(radian));
	set_element(matrix, 0, 1, -sin(radian));
	set_element(matrix, 1, 0, sin(radian));
	set_element(matrix, 1, 1, cos(radian));
}
