/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_element_ambient.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:00:16 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/24 19:24:48 by dmanoel-         ###   ########.fr       */
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
#include "ambient.h"

static int fill_struct(t_element_ambient *element, t_list *token_list)
{
	t_token				*token_tmp;
	int					status;

	token_tmp = (t_token *)ft_lstget(token_list, 2)->content;
	status = property_to_double(token_tmp, &element->radio);
	if (status != OK_CONVERT)
		return (status);
	token_tmp = (t_token *)ft_lstget(token_list, 4)->content;
	status = property_xyz_to_number(ft_lstget(token_list, 4), element->color);
	return (status);
}

static int	create_element(t_world *w, t_element_ambient *amb)
{
	t_ambient	*ambient;

	ambient = create_ambient();
	if (!ambient)
		return (ERR_BUILD_ELEMENT_MALLOC);
	ambient->radio = amb->radio;
	ambient->color.red = color_int_to_double(amb->color[RED]) * amb->radio;
	ambient->color.green = color_int_to_double(amb->color[GREEN]) * amb->radio;
	ambient->color.blue = color_int_to_double(amb->color[BLUE]) * amb->radio;
	w->ambient = ambient;
	return (OK_BUILD_ELEMENT);
}

int	build_element_ambient(t_world *w,t_list *token_list)
{
	t_element_ambient	element;
	int					status;

	status = fill_struct(&element, token_list);
	if (status != OK_BUILD_ELEMENT)
		return (ERR_BUILD_CONVERT_TOKENS);
	status = create_element(w, &element);
	return (status);
}
