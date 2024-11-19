/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_element_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:00:26 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/26 05:05:03 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build_element.h"
#include "build_world.h"
#include "world.h"
#include "libft.h"
#include "convert_errors.h"
#include "property_convert.h"
#include "array.h"
#include "color.h"
#include "light.h"

static int	fill_struct(t_element_light *lig, t_list *token_list)
{
	t_token	*token_tmp;
	int		status;

	lig->color[RED] = 255;
	lig->color[GREEN] = 255;
	lig->color[BLUE] = 255;
	status = property_xyz_to_number(ft_lstget(token_list, 2), lig->coor);
	if (status != OK_CONVERT)
		return (status);
	token_tmp = (t_token *)ft_lstget(token_list, 8)->content;
	status = property_to_number(token_tmp, &lig->radio);
	if (status != OK_CONVERT)
		return (status);
	if (BONUS == TRUE)
	{
		status = property_xyz_to_number(ft_lstget(token_list, 10), lig->color);
		if (status != OK_CONVERT)
			return (status);
	}
	return (status);
}

static int	create_element(t_world *w, t_element_light *lig)
{
	t_light	*light;
	t_color	color;
	t_list	*light_item;

	color.red = color_int_to_double(lig->color[RED]) * lig->radio;
	color.green = color_int_to_double(lig->color[GREEN]) * lig->radio;
	color.blue = color_int_to_double(lig->color[BLUE]) * lig->radio;
	light = create_light(&color, lig->coor[X], lig->coor[Y], \
	lig->coor[Z]);
	if (!light)
		return (ERR_BUILD_ELEMENT_MALLOC);
	light_item = ft_lstnew(light);
	if (!light_item)
	{
		destroy_light(&light);
		return (ERR_BUILD_ELEMENT_MALLOC);
	}
	ft_lstadd_back(&w->lights, light_item);
	return (OK_BUILD_ELEMENT);
}

int	build_element_light(t_world *w, t_list *token_list)
{
	t_element_light	element;
	int				status;

	status = fill_struct(&element, token_list);
	if (status != OK_BUILD_ELEMENT)
		return (ERR_BUILD_CONVERT_TOKENS);
	status = create_element(w, &element);
	return (status);
}
