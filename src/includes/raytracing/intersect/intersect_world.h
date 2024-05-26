/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_world.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 04:06:38 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/26 04:06:40 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_WORLD_H
# define INTERSECT_WORLD_H

# include "libft.h"
# include "world.h"
# include "ray.h"

t_list	*intersect_world(t_world *world, t_ray *ray);

#endif