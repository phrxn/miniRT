/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:14:20 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/06 20:23:30 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_SPHERE_H
# define INTERSECT_SPHERE_H

# include "libft.h"
# include "shape.h"
# include "ray.h"

# define A	0
# define B	1
# define C	2

# define T1 0
# define T2 1

# define MERR_DETERMINANT_MALLOC "Error when allocating point and vector \
matrices."
# define MERR_INTER_MALLOC "Error when allocating intersections or list."

t_list	*intersect_sphere(t_shape *shape, t_ray *ray_transformed);

#endif
