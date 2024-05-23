/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_element.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:52:32 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/24 21:10:45 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_ELEMENT_H
# define BUILD_ELEMENT_H

# include "world.h"
# include "line.h"
# include "transformation.h"

typedef struct s_element_ambient
{
	double radio;
	double color[3];
}	t_element_ambient;

typedef struct s_element_camera
{
	double	coordenates[3];
	double	direction[3];
	int		fov;
}	t_element_camera;

typedef struct s_element_light
{
	double	coordenates[3];
	double	radio;
	double	color[3];
}	t_element_light;

typedef struct s_element_sphere
{
	double	coordenates[3];
	double	diameter;
	double	color[3];
}	t_element_sphere;

typedef struct s_element_plane
{
	double	coordenates[3];
	double	direction[3];
	double	color[3];
}	t_element_plane;

typedef struct s_element_cylinder
{
	double	coordenates[3];
	double	direction[3];
	double	diameter;
	double	height;
	double	color[3];
}	t_element_cylinder;

int	build_element(t_world *world, t_line *line, t_transformation *transform);

int	build_element_ambient(t_world *w,t_list *token_list);

int	build_element_camera(t_world *w, t_list *token_list);

int	build_element_light(t_world *w, t_list *token_list);

int	build_element_shape(t_world *w, t_list *token_list, t_transformation *t);

#endif