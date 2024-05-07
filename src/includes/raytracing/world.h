/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:32:14 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/06 21:48:39 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "matrix.h"
# include "intersect.h"
# include "libft.h"
# include "canvas.h"

typedef struct s_light
{
	t_color		*intensity;
	t_matrix	*position;
}	t_light;

typedef struct s_world
{
	t_list	*intersections;
	t_list	*lights;
}	t_world;

#endif
