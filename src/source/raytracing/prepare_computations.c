/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_computations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:36:45 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/11 02:38:18 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prepare_computations.h"
#include "intersect.h"
#include "ray.h"
#include "libft.h"
#include "shape.h"
#include "matrix_utils.h"
#include "matrix_operations.h"
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
	free(pre_tmp);
	*pre = NULL;
}
