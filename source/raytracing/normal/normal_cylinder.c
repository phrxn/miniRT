/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:00:07 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/19 20:23:24 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "normal_cylinder.h"
#include "matrix.h"
#include "shape.h"
#include "matrix_alloc.h"
#include <math.h>

t_matrix	*normal_at_cylinder(t_shape *shape, t_matrix *point)
{
	t_matrix	*local_normal;
	t_cylinder	*cylinder;
	double		disc;

	local_normal = matrix_create_vector(0, 0, 0);
	if (!local_normal)
		return (NULL);
	cylinder = (t_cylinder *)shape->shape;
	disc = pow(point->elements[X], 2) + pow(point->elements[Z], 2);
	if (disc < 1 && point->elements[Y] >= cylinder->maximum - EPSILON)
	{
		local_normal->elements[Y] = 1;
		return (local_normal);
	}
	if (disc < 1 && point->elements[Y] <= cylinder->minimum + EPSILON)
	{
		local_normal->elements[Y] = -1;
		return (local_normal);
	}
	local_normal->elements[X] = point->elements[X];
	local_normal->elements[Z] = point->elements[Z];
	return (local_normal);
}
