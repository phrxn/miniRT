/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:16:50 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/19 01:51:33 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_PLANE_H
# define INTERSECT_PLANE_H

# include "libft.h"
# include "shape.h"
# include "ray.h"

t_list	*intersect_plane(t_shape *shape, t_ray *ray_transformed);

#endif