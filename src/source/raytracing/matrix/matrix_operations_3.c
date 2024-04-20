/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:25:52 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/04/11 22:46:42 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_operations.h"
#include "matrix.h"

static int	is_valid_multiplication(t_matrix *a, t_matrix *b, t_matrix *c)
{
	if (a->cols != b->rows)
		return (ERR_MATRIX_MUL_ROW_COL);
	if (c->rows != a->rows || c->cols != b->cols)
		return (ERR_MATRIX_MUL_INV_RESULT);
	return (OK_OPERATION);
}

static void	matrix_mult2(t_matrix *a, t_matrix *b, t_matrix *c)
{
	int		count_row;
	int		count_col;
	int		count_elements;
	double	result;

	count_row = 0;
	while (count_row < c->rows)
	{
		count_col = 0;
		while (count_col < c->cols)
		{
			result = 0;
			count_elements = 0;
			while (count_elements < a->cols)
			{
				result += get_element(a, count_row, count_elements)
					* get_element(b, count_elements, count_col);
				count_elements++;
			}
			set_element(c, count_row, count_col, result);
			count_col++;
		}
		count_row++;
	}
}

int	matrix_mult(t_matrix *a, t_matrix *b, t_matrix *c)
{
	int	check;

	check = is_valid_multiplication(a, b, c);
	if (check)
		return (check);
	matrix_mult2(a, b, c);
	return (OK_OPERATION);
}

void	matrix_transpose(t_matrix *a, t_matrix *b)
{
	unsigned int	size_matrix;
	int				count_rows;
	int				count_cols;
	int				temp_value;

	count_rows = 0;
	size_matrix = a->rows * a->cols;
	while (count_rows < a->rows)
	{
		count_cols = 0;
		while (count_cols < a->cols)
		{
			temp_value = get_element(a, count_rows, count_cols);
			set_element(b, count_cols, count_rows, temp_value);
			count_cols++;
		}
		count_rows++;
	}
}

int	matrix_inverse_4x4(t_matrix *matrix_4x4, t_matrix *result)
{
	double			determinant;
	double			cofactor;
	double			new_value;
	unsigned int	count_rows;
	unsigned int	count_cols;


	determinant = matrix_determinant_4x4(matrix_4x4, result);
	if (!determinant)
		return (ERR_DETERMINANT_ZERO);
	count_rows = 0;
	while(count_rows < 4)
	{
		count_cols = 0;
		while(count_cols < 4)
		{
			cofactor = cofactor_3x3(matrix_4x4, count_rows, count_cols);
			new_value = cofactor / determinant;
			set_element(result, count_cols, count_rows, new_value);
			count_cols++;
		}
		count_rows++;
	}
	return (OK_OPERATION);
}
