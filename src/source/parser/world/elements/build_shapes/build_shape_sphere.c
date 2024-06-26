/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_shape_sphere.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:00:32 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/26 05:05:03 by gacalaza         ###   ########.fr       */
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
#include "matrix_operations.h"
#include "matrix_utils.h"
#include "commons_build.h"

static int	fill_struct(t_element_sphere *sph, t_list *token_list)
{
	t_token	*token_tmp;
	int		status;

	status = property_xyz_to_number(ft_lstget(token_list, 2), sph->coor);
	if (status != OK_CONVERT)
		return (status);
	token_tmp = (t_token *)ft_lstget(token_list, 8)->content;
	status = property_to_number(token_tmp, &sph->diameter);
	if (status != OK_CONVERT)
		return (status);
	status = property_xyz_to_number(ft_lstget(token_list, 10), sph->color);
	return (status);
}

static void	fill_transformation(t_element_sphere *sph, t_transformation *t)
{
	double	radius;

	radius = sph->diameter / 2;
	matrix_fill_translation(t->translation, sph->coor[X], \
				sph->coor[Y], sph->coor[Z]);
	matrix_fill_scaling(t->scale, radius, radius, radius);
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

int	build_shape_sphere(t_world *world, t_list *token_list, t_transformation *t)
{
	t_element_sphere	sphere;
	int					status;
	t_shape				*shape;

	status = fill_struct(&sphere, token_list);
	if (status != OK_BUILD_ELEMENT)
		return (ERR_BUILD_CONVERT_TOKENS);
	shape = create_shape(TYPE_SPHERE);
	if (!shape)
		return (ERR_BUILD_ELEMENT_MALLOC);
	fill_transformation(&sphere, t);
	status = start_shape(shape, t, sphere.color);
	if (status != OK_BUILD_ELEMENT)
		return (status);
	return (put_in_world(shape, world));
}
