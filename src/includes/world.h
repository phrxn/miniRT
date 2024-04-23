/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:32:14 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/04/22 19:13:51 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "matrix.h"

typedef struct s_ambient
{
	char		identifier;
	t_matrix	color;
	double		lighting;
}	t_ambient;

typedef struct s_light
{
	char		identifier;
	t_matrix	coordinates;
	double		brightness;
}	t_light;

typedef struct s_camera
{
	char		identifier;
	t_matrix	coordinates;
	int			fov;
}	t_camera;

typedef struct s_world
{
	t_ambient	ambient;
	t_light		light;
	t_camera	camera;
}	t_world;

#endif
