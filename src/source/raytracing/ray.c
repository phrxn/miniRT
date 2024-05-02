/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:32:54 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/01 19:40:16 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "matrix_operations.h"
#include "matrix_alloc.h"
#include "matrix_utils.h"
#include "stdlib.h"
#include "libft.h"

t_matrix	*position(t_ray *ray, double t)
{
	t_matrix	*new_point;

	new_point = matrix_create_vector(0, 0, 0);
	if (!new_point)
		return (NULL);
	matrix_copy(ray->direction, new_point);
	matrix_mult_scalar(new_point, t);
	matrix_addition(new_point, ray->origin, new_point);
	return (new_point);
}

/**
 * create_ray - create a new ray, with its own origin and direction, copying
 * the values of the matrices passed as parameters
 * 
 * @origin:    the matrix to copy its values to ray oringin
 * @direction: the matrix to copy its values to direction
 * 
 * Return:
 * 	On success:
 * 		A new malloced ray
 *  On Failure:
 * 		NULL is retorned
*/
t_ray	*create_ray(t_matrix *origin, t_matrix *direction)
{
	t_ray	*new_ray;

	new_ray = ft_calloc(1, sizeof(*new_ray));
	if (!new_ray)
		return (NULL);
	new_ray->origin = matrix_create_point(0, 0, 0);
	new_ray->direction = matrix_create_point(0, 0, 0);
	if (!new_ray->origin || !new_ray->origin)
	{
		destroy_ray(&new_ray);
		return (NULL);
	}
	matrix_copy(origin, new_ray->origin);
	matrix_copy(direction, new_ray->direction);
	return (new_ray);
}

void	destroy_ray(t_ray **ray)
{
	t_ray	*ray_to_free;

	ray_to_free = *ray;
	if (!ray || !ray_to_free)
		return ;
	if (ray_to_free->origin)
		destroy_matrix(&ray_to_free->origin);
	if (ray_to_free->direction)
		destroy_matrix(&ray_to_free->direction);
	free (*ray);
	*ray = NULL;
}
