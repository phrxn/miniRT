/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:41:35 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/18 21:43:37 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADOW_H
# define SHADOW_H

# include "world.h"
# include "matrix.h"
# include "ray.h"
# include "libft.h"
# include "light.h"

# define MEER_START_VARS	"Start vars"

typedef struct s_is_shadowed_vars
{
	t_matrix	*v;
	t_matrix	*direction_v;
	t_list		*intersections;
	t_ray		*shadow_ray;
	double		distance;
}			t_is_shadowed_vars;

char	is_shadowed(t_world *world, t_light *light, t_matrix *point);

#endif