/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:14:34 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/19 04:03:29 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect_sphere.h"
#include "intersect.h"
#include "intersect_utils.h"
#include "matrix_alloc.h"
#include "matrix_operations.h"
#include "matrix.h"
#include "libft.h"
#include "math.h"
#include "messages.h"
#include "transform.h"

static void	calc_abc(double abc[3], t_ray *ray, t_matrix *sphere_to_ray, int *s)
{
	*s = matrix_dot(ray->direction, ray->direction, &abc[A]);
	if (!*s)
	{
		*s = matrix_dot(ray->direction, sphere_to_ray, &abc[B]);
		abc[B] *= 2;
	}
	if (!*s)
	{
		*s = matrix_dot(sphere_to_ray, sphere_to_ray, &abc[C]);
		abc[C] -= 1;
	}
}

static double	calc_disc(t_ray *ray, t_shape *sph, int *status, double abc[3])
{
	double		discriminant;
	t_matrix	*sphere_to_ray;
	t_sphere	*sphere;

	*status = 0;
	sphere = (t_sphere *)sph->shape;
	sphere_to_ray = matrix_create_subtraction(ray->origin, sphere->center);
	if (!sphere_to_ray)
		*status = 1;
	if (!*status)
		calc_abc(abc, ray, sphere_to_ray, status);
	discriminant = pow(abc[B], 2) - 4 * abc[A] * abc[C];
	destroy_matrix(&sphere_to_ray);
	return (discriminant);
}

static t_list	*make_lst(t_inter *i0, t_inter *i1, int *status)
{
	t_list	*item1;
	t_list	*item2;

	item1 = ft_lstnew(i0);
	if (!item1)
		*status = 1;
	if (!*status)
		item2 = ft_lstnew(i1);
	if (!*status)
		item1->next = item2;
	if (*status)
	{
		if (item1)
			free(item1);
		if (item2)
			free(item2);
		return (NULL);
	}
	return (item1);
}

static t_list	*make_inter(double t1, double t2, t_shape *shape, int *status)
{
	t_inter	*i0;
	t_inter	*i1;
	t_list	*item1;

	*status = 0;
	i0 = create_intersection(t1, shape);
	if (!i0)
		*status = 1;
	i1 = create_intersection(t2, shape);
	if (!i1)
		*status = 1;
	if (!*status)
		sort_intersection((void**)&i0, (void**)&i1);
	if (!*status)
		item1 = make_lst(i0, i1, status);
	if (*status)
	{
		if (i0)
			destroy_intersection(&i0);
		if (i1)
			destroy_intersection(&i1);
		show_error_method("intersect_sphere", MERR_INTER_MALLOC);
		return (NULL);
	}
	return (item1);
}

/**
 * intersect_sphere - create a t_list of intersections
*/
t_list	*intersect_sphere(t_shape *shape, t_ray *ray_transformed)
{
	int		status;
	double	discriminant;
	double	abc[3];
	double	ts[2];

	discriminant = calc_disc(ray_transformed, shape, &status, abc);
	if (status)
	{
		show_error_method("intersect_sphere", MERR_DETERMINANT_MALLOC);
		return (NULL);
	}
	if (discriminant < 0)
		return (NULL);
	ts[T1] = (-abc[B] - sqrt(discriminant)) / (2 * abc[A]);
	ts[T2] = (-abc[B] + sqrt(discriminant)) / (2 * abc[A]);
	return (make_inter(ts[T1], ts[T2], shape, &status));
}
