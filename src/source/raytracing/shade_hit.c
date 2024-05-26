/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 04:32:24 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/26 04:32:27 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shade_hit.h"
#include "color.h"
#include "color_operations.h"
#include "types.h"
#include "lighting.h"
#include "array.h"
#include "shadow.h"
#include <stdio.h>

static void	start_params(t_shade_vars *vars, t_world *world)
{
	fill_color(&vars->color_tmp, 0, 0, 0);
	fill_color(&vars->color, 0, 0, 0);
	vars->count = 0;
	vars->lst_light_size = ft_lstsize(world->lights);
	vars->is_shaded = FALSE;
	vars->light = NULL;
}

t_color	shade_hit(t_world *world, t_prepare_computations *pre)
{
	t_shade_vars		vars;
	t_lighting_params	lgt_params;
	t_list				*item;

	start_params(&vars, world);
	while (vars.count < vars.lst_light_size)
	{
		item = ft_lstget(world->lights, vars.count);
		vars.light = (t_light *)item->content;
		lgt_params.in_shadow = is_shadowed(world, vars.light, pre->over_point);
		lgt_params.material = &pre->shape->material;
		lgt_params.light = vars.light;
		lgt_params.point = pre->over_point;
		lgt_params.eyev = pre->eyev;
		lgt_params.normalv = pre->normalv;
		vars.color_tmp = lighting(&lgt_params, world);
		color_addition(&vars.color, &vars.color_tmp, &vars.color);
		(vars.count)++;
	}
	return (vars.color);
}
