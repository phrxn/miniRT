/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_shape_cylinder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:00:23 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/25 00:12:21 by dmanoel-         ###   ########.fr       */
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


static int fill_struct(t_element_cylinder	*cyl, t_list *token_list)
{
	t_token	*token_tmp;
	int		status;

	status = property_xyz_to_number(ft_lstget(token_list, 2), cyl->coordenates);
	if (status != OK_CONVERT)
		return (status);
	status = property_xyz_to_number(ft_lstget(token_list, 8), cyl->direction);
	if (status != OK_CONVERT)
		return (status);
	token_tmp = (t_token *)ft_lstget(token_list, 14)->content;
	status = property_to_double(token_tmp, &cyl->diameter);
	if (status != OK_CONVERT)
		return (status);
	token_tmp = (t_token *)ft_lstget(token_list, 16)->content;
	status = property_to_double(token_tmp, &cyl->height);
	if (status != OK_CONVERT)
		return (status);
	status = property_xyz_to_number(ft_lstget(token_list, 18), cyl->color);
	return (status);
}




static void	fill_transformation(t_element_cylinder *cyl, t_transformation *t)
{
	double	radius;
	double	height;

	radius =  cyl->diameter/2;
	height =  cyl->height/2;
	matrix_fill_translation(t->transformation, cyl->coordenates[X], cyl->coordenates[Y], cyl->coordenates[Z]);
	//tokens_to_rotation(t, cyl->direction);
	matrix_fill_scaling(t->scale, radius, height, radius);
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

int	build_shape_cylinder(t_world *wrl, t_list *token_list, t_transformation *t)
{
	t_element_cylinder	cylinder;
	int					status;
	t_shape				*shape;

	status = fill_struct(&cylinder, token_list);
	if (status != OK_BUILD_ELEMENT)
		return (ERR_BUILD_CONVERT_TOKENS);
	shape = create_shape(TYPE_PLANE);
	if (!shape)
		return (ERR_BUILD_ELEMENT_MALLOC);
	fill_transformation(&cylinder, t);
	fill_material(&shape->material);
	fill_color(&shape->material.color, cylinder.color[RED], cylinder.color[GREEN], cylinder.color[BLUE]);
	status = make_transformation(t);
	if (status != OK_OPERATION)
	{
		destroy_shape(&shape);
		return (ERR_BUILD_ELEMENT_MAKE_TRANSF_MATRIX);
	}
	matrix_copy(t->transformation, shape->transformation);
	matrix_copy(t->transformation_inv, shape->transformation_inv);
	return (put_in_world(shape, wrl));
}