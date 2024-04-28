/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:34:51 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/04/27 19:46:03 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_operations.h"
#include "matrix.h"

int	matrix_addition(t_matrix *a, t_matrix *b, t_matrix *c)
{
	int	count;
	int	matrix_size;

	count = 0;
	matrix_size = a->rows * a->cols;
	if (a->rows != b->rows)
		return (ERR_ROWS_SIZE);
	if (a->cols != b->cols)
		return (ERR_COLS_SIZE);
	while (count < matrix_size)
	{
		c->elements[count] = a->elements[count] + b->elements[count];
		count++;
	}
	return (OK_OPERATION);
}

int	matrix_subtraction(t_matrix *a, t_matrix *b, t_matrix *c)
{
	int	count;
	int	matrix_size;

	count = 0;
	matrix_size = a->rows * a->cols;
	if (a->rows != b->rows)
		return (ERR_ROWS_SIZE);
	if (a->cols != b->cols)
		return (ERR_COLS_SIZE);
	while (count < matrix_size)
	{
		c->elements[count] = a->elements[count] - b->elements[count];
		count++;
	}
	return (OK_OPERATION);
}

void	matrix_negation(t_matrix *a)
{
	int	count;
	int	matrix_size;

	count = 0;
	matrix_size = a->rows * a->cols;
	while (count < matrix_size)
	{
		a->elements[count] = -a->elements[count];
		count++;
	}
}

void	matrix_mult_scalar(t_matrix *a, double scalar)
{
	int	count;
	int	matrix_size;

	count = 0;
	matrix_size = a->rows * a->cols;
	while (count < matrix_size)
	{
		a->elements[count] *= scalar;
		count++;
	}
}

void	matrix_div_scalar(t_matrix *a, double scalar)
{
	int	count;
	int	matrix_size;

	count = 0;
	matrix_size = a->rows * a->cols;
	while (count < matrix_size)
	{
		a->elements[count] /= scalar;
		count++;
	}
}
