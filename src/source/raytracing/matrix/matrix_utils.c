/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:54:41 by gacalaza          #+#    #+#             */
/*   Updated: 2024/04/23 20:03:38 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_utils.h"
#include "matrix.h"
#include "types.h"

void	matrix_copy(t_matrix *from, t_matrix *to)
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
