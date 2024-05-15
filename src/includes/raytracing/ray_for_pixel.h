/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_for_pixel.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 04:34:35 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/15 18:36:12 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_FOR_PIXEL_H
# define RAY_FOR_PIXEL_H

# include "ray.h"
# include "camera.h"

typedef struct	s_ray_for_pixel_vars
{
	double 		xoffset;
	double 		yoffset;
	double 		world_x;
	double 		world_y;
	t_matrix	*inv_transformation;
	t_matrix	*pixel;
	t_matrix	*origin;
	t_matrix	*direction;

	t_matrix	*point_pixel;
	t_matrix	*point_origin;
}	t_ray_for_pixel_vars;

t_ray	*ray_for_pixel(t_camera *camera, int px, int py);

#endif