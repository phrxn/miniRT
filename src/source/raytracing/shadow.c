/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:41:41 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/18 22:11:04 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "light.h"
#include "intersect.h"
#include "intersect_world.h"
#include "intersect_utils.h"
#include "hit.h"
#include "matrix.h"
#include "matrix_alloc.h"
#include "matrix_operations.h"
#include "messages.h"
#include "ray.h"
#include "shadow.h"
#include "world.h"

static void	end_vars(t_is_shadowed_vars *vars)
{
	destroy_matrix(&vars->v);
	destroy_matrix(&vars->direction_v);
	destroy_ray(&vars->shadow_ray);
	ft_lstclear(&vars->intersections, destroy_intersection2);
}

static int	init_vars(t_is_shadowed_vars *vars, t_light *light, t_matrix *point)
{
	vars->v = matrix_create_subtraction(light->position, point);
	vars->direction_v = matrix_create_vector(0, 0, 0);
	if (!vars->v || !vars->direction_v)
	{
		end_vars(vars);
		return (1);
	}
	vars->distance = matrix_get_magnitude(vars->v);
	matrix_normalization(vars->v, vars->direction_v);
	vars->intersections = NULL;
	vars->shadow_ray = create_ray(point, vars->direction_v);
	if (!vars->shadow_ray)
	{
		end_vars(vars);
		return (1);
	}
	return (0);
}

char	is_shadowed(t_world *world, t_light *light, t_matrix *point)
{
	t_is_shadowed_vars	vars;
	t_inter				*the_hit;
	char				is_shadowed;

	is_shadowed = FALSE;
	if (init_vars(&vars, light, point))
	{
		show_error_method("is_shadowed", MEER_START_VARS);
		return (is_shadowed);
	}
	vars.intersections = intersect_world(world, vars.shadow_ray);
	the_hit = hit(vars.intersections);
	if (the_hit && the_hit->t < vars.distance)
		is_shadowed = TRUE;
	end_vars(&vars);
	return (is_shadowed);
}
