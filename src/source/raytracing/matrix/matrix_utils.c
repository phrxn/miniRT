/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:54:41 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/09 21:38:05 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_utils.h"
#include "matrix.h"
#include "types.h"

void		matrix_copy(t_matrix *from, t_matrix *to)
{
	t_uint	size;
	t_uint	count;

	count = 0;
	size = from->rows * from->cols;
	to->rows = from->rows;
	to->cols = from->cols;
	while (size > count)
	{
		to->elements[count] = from->elements[count];
		count++;
	}
}

t_matrix	*matrix_copy_create(t_matrix *to_copy)
{
	t_matrix	*new_matrix;

	new_matrix = create_matrix(to_copy->rows, to_copy->cols);
	if (!new_matrix)
		return (NULL);
	matrix_copy(to_copy, new_matrix);
	return (new_matrix);
}
