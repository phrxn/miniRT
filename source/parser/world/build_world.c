/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:09:03 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/26 04:42:25 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build_world.h"
#include "build_world_errors.h"
#include "build_element.h"
#include "transformation.h"
#include "world.h"
#include "libft.h"
#include "line.h"
#include "array.h"

static int	build_elements(t_world *w, t_list *list_line, t_transformation *tr)
{
	int		count;
	int		list_size;
	t_line	*line_item;
	int		status;

	count = 0;
	list_size = ft_lstsize(list_line);
	status = 0;
	while (count < list_size)
	{
		fill_transformation_identity(tr);
		line_item = (t_line *)ft_lstget(list_line, count)->content;
		status = build_element(w, line_item, tr);
		if (status)
			break ;
		count++;
	}
	if (status != OK_BUILD_ELEMENT)
		show_error_build_element(status, line_item);
	return (status);
}

/**
 * build_a_world - create and fill world
 *
 * @valid_list_line: a valid line list (the list needs to come from the parser)
 *
 * Return:
 * 	On sucessful:
 * 		a malloced pointer to world
 *  On failure:
 * 		(NULL) is returned
*/
t_world	*build_a_world(t_list *valid_list_line)
{
	t_transformation	*transf;
	t_world				*world;
	int					status;

	world = ft_calloc(1, sizeof(*world));
	if (!world)
	{
		show_error_build_world(ERR_MALLOC_WORLD);
		return (NULL);
	}
	transf = create_transformation();
	if (!transf)
	{
		destroy_world(&world);
		show_error_build_world(ERR_MALLOC_TRANSFOR_MATRIX);
		return (NULL);
	}
	status = build_elements(world, valid_list_line, transf);
	destroy_transformation(&transf);
	if (status != OK_BUILD_ELEMENT)
		destroy_world(&world);
	return (world);
}
