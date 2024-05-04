/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:20:33 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/04 15:36:59 by gacalaza         ###   ########.fr       */
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
	t_matrix	*inverse;
	t_ray		*ray_transformed;

	inverse = matrix_create_inverse(shape->transformation);
	if (!inverse)
	{
		show_error_method("transform_ray", MERR_INVERSE_MATRIX);
		return (NULL);
	}
	ray_transformed = transform(ray, inverse);
	if (!ray_transformed)
		show_error_method("transform_ray", MERR_CREATE_RAY_TRANS);
	destroy_matrix(&inverse);
	return (ray_transformed);
}
