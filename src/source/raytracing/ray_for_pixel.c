/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_for_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 04:40:53 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/26 05:08:49 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_for_pixel.h"
#include "matrix_alloc.h"
#include "matrix_operations.h"
#include "matrix_errors.h"

static void	end_vars(t_ray_pixel_vars *vars)
{
	destroy_matrix(&vars->pixel);
	destroy_matrix(&vars->origin);
	destroy_matrix(&vars->direction);
	destroy_matrix(&vars->point_pixel);
	destroy_matrix(&vars->point_origin);
}

static int	start_vars(t_ray_pixel_vars *vars, t_camera *cam, int px, int py)
{
	vars->xoffset = (px + 0.5) * cam->pixel_size;
	vars->yoffset = (py + 0.5) * cam->pixel_size;
	vars->world_x = cam->half_width - vars->xoffset;
	vars->world_y = cam->half_height - vars->yoffset;
	vars->inv_transformation = cam->transformation_inv;
	vars->pixel = matrix_create_point(0, 0, 0);
	vars->origin = matrix_create_point(0, 0, 0);
	vars->direction = matrix_create_vector(0, 0, 0);
	vars->point_pixel = matrix_create_point(vars->world_x, vars->world_y, -1);
	vars->point_origin = matrix_create_point(0, 0, 0);
	if (!vars->inv_transformation || !vars->pixel || !vars->origin
		|| !vars->direction || !vars->point_pixel || !vars->point_origin)
	{
		end_vars(vars);
		return (1);
	}
	return (0);
}

t_ray	*ray_for_pixel(t_camera *camera, int px, int py)
{
	t_ray_pixel_vars	vars;
	t_ray				*ray;
	int					status;

	if (start_vars(&vars, camera, px, py))
		return (NULL);
	status = 0 ;
	status = matrix_mult(vars.inv_transformation, vars.point_pixel, vars.pixel);
	if (status != OK_OPERATION)
		show_error_matrix("ray_for_pixel", status);
	status = matrix_mult(vars.inv_transformation, vars.point_origin, \
		vars.origin);
	if (status != OK_OPERATION)
		show_error_matrix("ray_for_pixel", status);
	status = matrix_subtraction(vars.pixel, vars.origin, vars.direction);
	if (status != OK_OPERATION)
		show_error_matrix("ray_for_pixel", status);
	status = matrix_normalization(vars.direction, vars.direction);
	if (status != OK_OPERATION)
		show_error_matrix("ray_for_pixel", status);
	ray = create_ray(vars.origin, vars.direction);
	end_vars(&vars);
	return (ray);
}
