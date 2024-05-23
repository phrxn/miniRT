/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:52:32 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/24 22:19:57 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "build_element.h"
# include "build_world.h"
# include "world.h"
# include "line.h"
# include "select_element.h"
# include "transform.h"

int	build_element(t_world *world, t_line *line, t_transformation *transform)
{
	t_list			*token_list;
	t_element_type	element_type;

	token_list = line->token_list;
	element_type = get_element_type(token_list);
	if (element_type == ambient)
		return (build_element_ambient(world, token_list));
	if (element_type == camera)
		return (build_element_camera(world, token_list));
	if (element_type == light)
		return (build_element_light(world, token_list));
	if (element_type == sphere)
		return (build_element_shape(world, token_list, transform));
	if (element_type == plane)
		return (build_element_shape(world, token_list, transform));
	if (element_type == cylinder)
		return (build_element_shape(world, token_list, transform));
	return (ERR_BUILD_ELEMENT_NOT_EXIT);
}
