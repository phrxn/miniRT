/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 19:19:47 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/04/06 15:03:50 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <stdlib.h>
#include "libft.h"

#ifdef TEST //delete.... please!!!
	void	*malloc_mock_matrix(size_t size);
	void	*ft_calloc_mock_matrix(size_t nitems, size_t size);
	void	free_mock_matrix(void *freez);
	#define malloc malloc_mock_matrix
	#define ft_calloc ft_calloc_mock_matrix
	#define free free_mock_matrix
#endif

static int	get_position(t_matrix *matrix, int row, int col)
{
	return (row * matrix->cols + col);
}

double	get_element(t_matrix *matrix, int row, int col)
{
	int	position;

	position = get_position(matrix, row, col);
	return (matrix->elements[position]);
}

void	set_element(t_matrix *matrix, int row, int col, double value)
{
	int	position;

	position = get_position(matrix, row, col);
	matrix->elements[position] = value;
}

t_matrix	*create_matrix(int rows, int cols)
{
	int			elements_amount;
	t_matrix	*matrix;

	elements_amount = rows * cols;
	matrix = malloc(sizeof(*matrix));
	if (!matrix)
		return (NULL);
	matrix->rows = rows;
	matrix->cols = cols;
	matrix->elements = ft_calloc(elements_amount, sizeof(*matrix->elements));
	if (!matrix->elements)
		destroy_matrix(&matrix);
	return (matrix);
}

void	destroy_matrix(t_matrix **matrix)
{
	if (!matrix || !*matrix)
		return ;
	if ((*matrix)->elements)
		free((*matrix)->elements);
	free(*matrix);
	*matrix = NULL;
}
