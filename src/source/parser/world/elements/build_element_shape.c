/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_element_shape.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:56:27 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/24 22:20:45 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build_element.h"
#include "build_shape.h"
#include "build_world.h"
#include "world.h"
#include "select_element.h"

int	build_element_shape(t_world *w, t_list *token_list, t_transformation *t)
{
	t_element_type	type;

	type = get_element_type(token_list);
	if (type == cylinder)
		return (build_shape_cylinder(w, token_list, t));
	if (type == plane)
		return (build_shape_plane(w,token_list, t));
	if (type == sphere)
		return (build_shape_sphere(w,token_list, t));
	return (ERR_BUILD_ELEMENT_NOT_EXIT);
}
