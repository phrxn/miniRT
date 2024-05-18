/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:07:24 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/19 02:39:09 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "intersect_sphere.h"
#include "intersect_plane.h"
#include "messages.h"
#include "transform.h"

static	t_list	*select_intersect(t_shape *shape, t_ray *ray_transformed)
{
	if (shape->type == TYPE_SPHERE)
		return (intersect_sphere(shape, ray_transformed));
	if (shape->type == TYPE_PLANE)
		return (intersect_plane(shape, ray_transformed));
	else
		show_error_method("intersect", MERR_INVALID_OBJ_TYPE);
	return (NULL);
}

t_list	*intersect(t_shape *shape, t_ray *ray)
{
	t_list	*list_intersections;
	t_ray	*ray_transformed;

	ray_transformed = transform_ray(shape, ray);
	if (!ray_transformed)
		return (NULL);
	list_intersections = select_intersect(shape, ray_transformed);
	destroy_ray(&ray_transformed);
	return (list_intersections);
}
