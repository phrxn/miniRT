/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:32:14 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/24 16:56:52 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "libft.h"
# include "shape.h"
# include "ray.h"
# include "camera.h"
# include "canvas.h"
# include "ambient.h"

typedef struct s_world
{
	t_ambient	*ambient;
	t_camera	*camera;
	t_list		*intersections;
	t_list		*lights;
	t_list		*shapes;
}	t_world;

void	destroy_world(t_world **world);

t_color	color_at(t_world *world, t_ray *ray);

void	render(t_camera *camera, t_world *world, t_canvas *canvas);

#endif
