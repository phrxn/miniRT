/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:56:19 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/18 20:37:11 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lighting.h"
#include "canvas.h"
#include "color.h"
#include "color_operations.h"
#include "matrix_alloc.h"
#include "matrix_operations.h"
#include "messages.h"
#include "reflect.h"
#include <math.h>

static int	start_vars(t_lighting_vars *vars)
{
	fill_color(&vars->diffuse, 0, 0, 0);
	fill_color(&vars->specular, 0, 0, 0);
	fill_color(&vars->ambient, 0, 0, 0);
	fill_color(&vars->effective_color, 0, 0, 0);
	fill_color(&vars->return_color, 0, 0, 0);
	vars->lightv = matrix_create_vector(0, 0, 0);
	vars->reflectv = NULL;
	vars->light_dot_normal = 0;
	vars->reflect_dot_eye = 0;
	vars->factor = 0;
	if (!vars->lightv)
	{
		destroy_matrix(&vars->lightv);
		return (1);
	}
	return (0);
}

static void	end_vars(t_lighting_vars *vars)
{
	destroy_matrix(&vars->lightv);
	destroy_matrix(&vars->reflectv);
}

static int	calc_color(t_lighting_params *params, t_lighting_vars *vars)
{
	color_mult_scalar(&vars->effective_color, params->material->diffuse, \
								&vars->diffuse);
	color_mult_scalar(&vars->diffuse, vars->light_dot_normal, &vars->diffuse);
	matrix_negation(vars->lightv);
	vars->reflectv = reflect(vars->lightv, params->normalv);
	if (!vars->reflectv)
		return (1);
	matrix_dot(vars->reflectv, params->eyev, &vars->reflect_dot_eye);
	if (vars->reflect_dot_eye < 0)
		fill_color(&vars->specular, 0, 0, 0);
	else
	{
		vars->factor = pow(vars->reflect_dot_eye, params->material->shininess);
		color_mult_scalar(&params->light->intensity, \
						params->material->specular, &vars->specular);
		color_mult_scalar(&vars->specular, vars->factor, &vars->specular);
	}
	return (0);
}

t_color	lighting(t_lighting_params *params)
{
	t_lighting_vars	vars;
	int				status;

	status = start_vars(&vars);
	if (status)
	{
		show_error_method("lighting", MERR_MALLOC_LIGHTV);
		return (vars.return_color);
	}
	color_mult(&params->material->color, &params->light->intensity, \
						&vars.effective_color);
	matrix_subtraction(params->light->position, params->point, vars.lightv);
	matrix_normalization(vars.lightv, vars.lightv);
	color_mult_scalar(&vars.effective_color, params->material->ambient, \
							&vars.ambient);
	matrix_dot(vars.lightv, params->normalv, &vars.light_dot_normal);
	if (vars.light_dot_normal > 0 || !params->in_shadow)
		status = calc_color(params, &vars);
	if (!status)
	{
		color_addition(&vars.diffuse, &vars.ambient, &vars.return_color);
		color_addition(&vars.return_color, &vars.specular, &vars.return_color);
	}
	end_vars(&vars);
	return (vars.return_color);
}
