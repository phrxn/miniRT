/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations_4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:29:06 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/10 00:27:52 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_operations.h"
#include "matrix.h"

#include <stdio.h>

static int	jump_element(t_matrix *matrix, int count, int jump_r, int jump_c)
{
	int	row;
	int	col;

	row = count / matrix->cols;
	col = count % matrix->cols;
	if (row == jump_r)
		return (1);
	if (col == jump_c)
		return (1);
	return (0);
}

static void	submatrix(t_matrix *parent, t_matrix *child, int jump_r, int jump_c)
{
	int	count_chi;
	int	count_par;
	int	parent_size;

	count_chi = 0;
	count_par = 0;
	parent_size = parent->rows * parent->cols;
	while (count_par < parent_size)
	{
		if (!jump_element(parent, count_par, jump_r, jump_c))
		{
			child->elements[count_chi] = parent->elements[count_par];
			count_chi++;
		}
		count_par++;
	}
}

static double	determinant_sarrus_3x3(t_matrix *matrix_3x3)
{
	double	det;
	double	*e;

	e = matrix_3x3->elements;
	det = e[0] * e[4] * e[8] + e[1] * e[5] * e[6] + e[2] * e[3] * e[7]
		- e[2] * e[4] * e[6] - e[0] * e[5] * e[7] - e[1] * e[3] * e[8];
	return (det);
}

double	cofactor_3x3(t_matrix *matrix_4x4, int row, int col)
{
	double		determinant;
	double		matrix_3x3_elements[9];
	t_matrix	matrix3x3_tmp;

	matrix3x3_tmp.rows = 3;
	matrix3x3_tmp.cols = 3;
	matrix3x3_tmp.elements = matrix_3x3_elements;
	submatrix(matrix_4x4, &matrix3x3_tmp, row, col);
	determinant = determinant_sarrus_3x3(&matrix3x3_tmp);
	if ((row + col) % 2)
		return (determinant * -1);
	return (determinant);
}

double	matrix_determinant_4x4(t_matrix *matrix_4x4)
{
	double			determinant;
	double			cofactor3x3;
	unsigned int	count;

	determinant = 0;
	count = 0;
	while (count < 4)
	{
		cofactor3x3 = cofactor_3x3(matrix_4x4, 0, count);
		determinant += (cofactor3x3 * matrix_4x4->elements[count]);
		count++;
	}
	return (determinant);
}
