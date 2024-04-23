/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_alloc_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:02:02 by gacalaza          #+#    #+#             */
/*   Updated: 2024/04/22 22:07:10 by gacalaza         ###   ########.fr       */
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