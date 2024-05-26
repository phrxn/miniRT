/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_shape_plane.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:00:29 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/26 05:08:01 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build_shape.h"
#include "build_element.h"
#include "build_world.h"
#include "property_convert.h"
#include "convert_errors.h"
#include "array.h"
#include "matrix_fill.h"
#include "material.h"
#include "matrix_rotation_convert.h"
#include "matrix_operations.h"
#include "matrix_utils.h"
#include "commons_build.h"

static int	fill_struct(t_element_plane	*pla, t_list *token_list)
{
	int		status;

	status = property_xyz_to_number(ft_lstget(token_list, 2), pla->coor);
	if (status != OK_CONVERT)
		return (status);
	status = property_xyz_to_number(ft_lstget(token_list, 8), pla->direction);
	if (status != OK_CONVERT)
		return (status);
	status = property_xyz_to_number(ft_lstget(token_list, 14), pla->color);
	return (status);
}

static void	fill_transformation(t_element_plane *pla, t_transformation *t)
{
	tokens_to_rotation(t, pla->direction);
	matrix_fill_translation(t->translation, pla->coor[X], \
		pla->coor[Y], pla->coor[Z]);
}

static int	put_in_world(t_shape *shape, t_world *world)
{
	t_list	*item_shape;

	item_shape = ft_lstnew(shape);
	if (!item_shape)
	{
		destroy_shape2(shape);
		return (ERR_BUILD_ELEMENT_MALLOC);
	}
	ft_lstadd_back(&world->shapes, item_shape);
	return (OK_BUILD_ELEMENT);
}

int	build_shape_plane(t_world *world, t_list *token_list, t_transformation *t)
{
	t_element_plane		plane;
	int					status;
	t_shape				*shape;

	status = fill_struct(&plane, token_list);
	if (status != OK_BUILD_ELEMENT)
		return (ERR_BUILD_CONVERT_TOKENS);
	shape = create_shape(TYPE_PLANE);
	if (!shape)
		return (ERR_BUILD_ELEMENT_MALLOC);
	fill_transformation(&plane, t);
	status = start_shape(shape, t, plane.color);
	if (status != OK_BUILD_ELEMENT)
		return (status);
	return (put_in_world(shape, world));
}
