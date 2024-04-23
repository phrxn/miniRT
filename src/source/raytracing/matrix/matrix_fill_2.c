/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_fill_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:56:46 by gacalaza          #+#    #+#             */
/*   Updated: 2024/04/22 21:48:06 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_fill.h"
#include "matrix.h"
#include "types.h"

void	matrix_fill_scaling(t_matrix *matrix, double x, double y, double z)
{
	matrix_fill_zero(matrix);
	matrix_fill_identity(matrix);
	set_element(matrix, 0, 0, x);
	set_element(matrix, 1, 1, y);
	set_element(matrix, 2, 2, z);
}

void	matrix_fill_translation(t_matrix *matrix, double x, double y, double z)
{
	matrix_fill_zero(matrix);
	matrix_fill_identity(matrix);
	set_element(matrix, 0, 3, x);
	set_element(matrix, 1, 3, y);
	set_element(matrix, 2, 3, z);
}

void	matrix_fill_shearing(t_matrix *matrix, t_shearing *shearing)
{
	matrix_fill_zero(matrix);
	matrix_fill_identity(matrix);
	set_element(matrix, 0, 1, shearing->x_to_y);
	set_element(matrix, 0, 2, shearing->x_to_z);
	set_element(matrix, 1, 0, shearing->y_to_x);
	set_element(matrix, 1, 2, shearing->y_to_z);
	set_element(matrix, 2, 0, shearing->z_to_x);
	set_element(matrix, 2, 1, shearing->z_to_y);
}
