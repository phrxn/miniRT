/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:40:31 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/19 19:52:17 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect_cylinder.h"
#include "ray.h"
#include <math.h>

char	check_cap_cylinder(t_ray *ray, double t)
{
	double	x;
	double	z;

	x = ray->origin->elements[X] + t * ray->direction->elements[X];
	z = ray->origin->elements[Z] + t * ray->direction->elements[Z];
	return ((pow(x, 2) + pow(z, 2)) <= 1);
}
