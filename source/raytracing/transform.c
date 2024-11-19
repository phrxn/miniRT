/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:20:33 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/18 16:30:16 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"
#include "matrix.h"
#include "matrix_operations.h"
#include "matrix_alloc.h"
#include "ray.h"
#include "messages.h"
#include "shape.h"

t_ray	*transform(t_ray *ray, t_matrix *matrix)
{
	t_ray	*new_ray;
	int		status;

	new_ray = create_ray(ray->origin, ray->direction);
	if (!new_ray)
	{
		show_error_method("transform", MERR_MALLOC_NEW_RAY);
		return (NULL);
	}
	status = matrix_mult(matrix, ray->origin, new_ray->origin);
	if (status != OK_OPERATION)
		show_error_method("transform", MERR_MULT_ORIGIN);
	status = matrix_mult(matrix, ray->direction, new_ray->direction);
	if (status != OK_OPERATION)
		show_error_method("transform", MERR_MULT_DIRECTION);
	return (new_ray);
}

t_ray	*transform_ray(t_shape *shape, t_ray *ray)
{
	t_ray		*ray_transformed;

	ray_transformed = transform(ray, shape->transformation_inv);
	if (!ray_transformed)
		show_error_method("transform_ray", MERR_CREATE_RAY_TRANS);
	return (ray_transformed);
}
