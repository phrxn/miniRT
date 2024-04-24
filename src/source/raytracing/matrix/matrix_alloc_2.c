/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_alloc_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:02:02 by gacalaza          #+#    #+#             */
/*   Updated: 2024/04/23 20:10:20 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_alloc.h"
#include "matrix.h"
#include "matrix_operations.h"
#include "matrix_fill.h"
#include "messages.h"
#include "matrix_errors.h"
#include <stdlib.h>

t_matrix	*matrix_create_translate(double x, double y, double z)
{
	t_matrix	*new_matrix;

	new_matrix = create_matrix(4, 4);
	if (!new_matrix)
		return (new_matrix);
	matrix_fill_translation(new_matrix, x, y, z);
	return (new_matrix);
}

t_matrix	*matrix_create_scaling(double x, double y, double z)
{
	t_matrix	*new_matrix;

	new_matrix = create_matrix(4, 4);
	if (!new_matrix)
		return (new_matrix);
	matrix_fill_scaling(new_matrix, x, y, z);
	return (new_matrix);
}

t_matrix	*matrix_create_rot_x(double radians)
{
	t_matrix	*new_matrix;

	new_matrix = create_matrix(4, 4);
	if (!new_matrix)
		return (new_matrix);
	matrix_fill_rot_x(new_matrix, radians);
	return (new_matrix);
}

t_matrix	*matrix_create_rot_y(double radians)
{
	t_matrix	*new_matrix;

	new_matrix = create_matrix(4, 4);
	if (!new_matrix)
		return (new_matrix);
	matrix_fill_rot_y(new_matrix, radians);
	return (new_matrix);
}

t_matrix	*matrix_create_rot_z(double radians)
{
	t_matrix	*new_matrix;

	new_matrix = create_matrix(4, 4);
	if (!new_matrix)
		return (new_matrix);
	matrix_fill_rot_z(new_matrix, radians);
	return (new_matrix);
}
