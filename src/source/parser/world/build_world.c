/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:09:03 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/23 14:17:27 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build_world.h"
#include "build_world_errors.h"
#include "transformation.h"
#include "world.h"
#include "libft.h"


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
	(void) transf;
	(void) world;
	(void)	valid_list_line;
	return (NULL);
}