/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:34:47 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/06 21:39:45 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "normal.h"
#include "normal_sphere.h"
#include "matrix.h"
#include "shape.h"
#include "matrix_alloc.h"
#include "matrix_operations.h"
#include "messages.h"

static t_matrix	*normal_select(t_shape *shape, t_matrix *point)
{
	if (shape->type == TYPE_SPHERE)
		return (normal_at_sphere(shape, point));
	else
		show_error_method("normal_select", MERR_INVALID_OBJ_TYPE);
	return (NULL);
}

static t_matrix	*point_to_obj(t_shape *sp, t_matrix *pnt, t_matrix *inv, int *s)
{
	t_matrix	*local_point;

	local_point = NULL;
	if (*s == 0)
		local_point = matrix_create_mult(inv, pnt);
	if (!local_point)
		*s = 1;
	return (local_point);
}

static t_matrix	*point_to_world(t_matrix *inv, t_matrix *local_norm, int *s)
{
	t_matrix	*transpose;
	t_matrix	*world_normal;

	transpose = matrix_create_transpose(inv);
	if (!transpose)
		*s = 1;
	if (*s == 0)
		world_normal = matrix_create_mult(transpose, local_norm);
	if (!world_normal)
		*s = 1;
	if (*s == 0)
		world_normal->elements[W] = 0;
	destroy_matrix(&transpose);
	return (world_normal);
}

void	start_vars(t_normal	*var)
{
	var->inv = NULL;
	var->local_point = NULL;
	var->local_nml = NULL;
	var->world_normal = NULL;
	var->status = 0;
}

t_matrix	*normal_at(t_shape *shape, t_matrix *point)
{
	t_normal	var;

	start_vars(&var);
	var.inv = matrix_create_inverse(shape->transformation);
	if (!var.inv)
		var.status = 1;
	if (var.status == 0)
		var.local_point = point_to_obj(shape, point, var.inv, &var.status);
	if (var.status == 0)
		var.local_nml = normal_select(shape, var.local_point);
	destroy_matrix(&var.local_point);
	if (!var.local_nml)
		var.status = 1;
	if (var.status == 0)
		var.world_normal = point_to_world(var.inv, var.local_nml, &var.status);
	destroy_matrix(&var.local_nml);
	destroy_matrix(&var.inv);
	if (var.status == 0)
		var.status = matrix_normalization(var.world_normal, var.world_normal);
	if (var.status != OK_OPERATION)
	{
		show_error_method("normal_at", MERR_MATRIX_NORMALIZATION);
		destroy_matrix(&var.world_normal);
	}
	return (var.world_normal);
}
