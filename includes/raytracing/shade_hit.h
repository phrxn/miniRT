/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_hit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 04:09:11 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/26 04:21:41 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADE_HIT_H
# define SHADE_HIT_H

# include "color.h"
# include "world.h"
# include "prepare_computations.h"
# include "types.h"
# include "light.h"

typedef struct s_shade_vars
{
	t_color	color_tmp;
	t_color	color;
	t_uint	lst_light_size;
	t_uint	count;
	char	is_shaded;
	t_light	*light;
}	t_shade_vars;

t_color	shade_hit(t_world *world, t_prepare_computations *pre);

#endif