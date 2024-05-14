/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:32:14 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/13 21:21:02 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "world.h"
# include "libft.h"
# include "intersect_world.h"
# include "intersect_utils.h"
# include "shape.h"
# include "light.h"

void	create_world(void)
{
}

void	destroy_world(t_world **world)
{
	t_world	*world_tmp;

	if (!world || !*world)
		return ;
	world_tmp = *world;
	if (world_tmp->intersections)
		ft_lstclear(&world_tmp->intersections, destroy_intersection2);
	if (world_tmp->lights)
		ft_lstclear(&world_tmp->lights, destroy_light2);
	if (world_tmp->shapes)
		ft_lstclear(&world_tmp->shapes, destroy_shape2);
	free(world_tmp);
}
