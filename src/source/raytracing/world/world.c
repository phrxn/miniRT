/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:32:14 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/16 01:57:27 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "color.h"
#include "camera.h"
#include "canvas.h"
#include "hit.h"
#include "libft.h"
#include "intersect_world.h"
#include "intersect_utils.h"
#include "shape.h"
#include "shade_hit.h"
#include "light.h"
#include "prepare_computations.h"
#include "ray.h"
#include "ray_for_pixel.h"

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

t_color	color_at(t_world *world, t_ray *ray)
{
	t_color					color_hit;
	t_list					*intersects;
	t_inter					*inter;
	t_prepare_computations	*pre;

	fill_color(&color_hit, 0, 0, 0);
	intersects = intersect_world(world, ray);
	if (!intersects)
		return (color_hit);
	inter = hit(intersects);
	if (inter)
	{
		pre = create_pre_computations(inter, ray);
		color_hit = shade_hit(world, pre);
		destroy_pre_computations(&pre);
	}
	ft_lstclear(&intersects, destroy_intersection2);
	return (color_hit);
}

void	render(t_camera *camera, t_world *world, t_canvas *canvas)
{
	int		count_y;
	int		count_x;
	t_ray	*ray;
	t_color	color;

	count_y = 0;
	while(count_y < canvas->height)
	{
		count_x = 0;
		while (count_x < canvas->width)
		{
			ray = ray_for_pixel(camera, count_x, count_y);
			if (!ray)
				continue ;
			color = color_at(world, ray);
			set_pixel(canvas, count_y, count_x, &color);
			destroy_ray(&ray);
			count_x++;
		}
		count_y++;
	}
}
