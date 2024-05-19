/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_computations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:36:45 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/19 16:59:29 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prepare_computations.h"
#include "intersect.h"
#include "ray.h"
#include "libft.h"
#include "shape.h"
#include "matrix_utils.h"
#include "matrix_operations.h"
#include "matrix_alloc.h"
#include "normal.h"

static void	check_hit_inside(t_prepare_computations *pre)
{
	double	dot;

	matrix_dot(pre->normalv, pre->eyev, &dot);
	if (dot < 0)
	{
		pre->inside = TRUE;
		matrix_negation(pre->normalv);
	}
}

static void	create_over_point(t_prepare_computations *pre)
{
	t_matrix	*temp_normal_v;

	temp_normal_v = matrix_create_vector(0, 0, 0);
	pre->over_point = matrix_create_point(0, 0, 0);
	if (!temp_normal_v || !pre->over_point)
	{
		destroy_pre_computations(&pre);
		return ;
	}
	matrix_copy(pre->normalv, temp_normal_v);
	matrix_mult_scalar(temp_normal_v, EPSILON);
	matrix_addition(pre->point, temp_normal_v, pre->over_point);
	destroy_matrix(&temp_normal_v);
}

t_prepare_computations	*create_pre_computations(t_inter *inter, t_ray *ray)
{
	t_prepare_computations	*pre;

	pre = ft_calloc(1, sizeof(*pre));
	if (!pre)
		return (NULL);
	pre->t = inter->t;
	pre->inside = FALSE;
	pre->shape = create_shape_copy(inter->shape);
	pre->point = position(ray, pre->t);
	pre->eyev = matrix_copy_create(ray->direction);
	if (!pre->shape || !pre->point || !pre->eyev)
	{
		destroy_pre_computations(&pre);
		return (NULL);
	}
	matrix_negation(pre->eyev);
	pre->normalv = normal_at(inter->shape, pre->point);
	if (!pre->normalv)
	{
		destroy_pre_computations(&pre);
		return (NULL);
	}
	check_hit_inside(pre);
	create_over_point(pre);
	return (pre);
}

void	destroy_pre_computations(t_prepare_computations **pre)
{
	t_prepare_computations	*pre_tmp;

	if (!pre || !*pre)
		return ;
	pre_tmp = *pre;
	if (pre_tmp->shape)
		destroy_shape(&pre_tmp->shape);
	if (pre_tmp->point)
		destroy_matrix(&pre_tmp->point);
	if (pre_tmp->eyev)
		destroy_matrix(&pre_tmp->eyev);
	if (pre_tmp->normalv)
		destroy_matrix(&pre_tmp->normalv);
	if (pre_tmp->over_point)
		destroy_matrix(&pre_tmp->over_point);
	free(pre_tmp);
	*pre = NULL;
}
