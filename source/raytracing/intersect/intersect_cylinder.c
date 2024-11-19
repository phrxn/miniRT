/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:18:19 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/19 20:27:36 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect_cylinder.h"
#include "intersect.h"
#include "intersect_utils.h"
#include "matrix_alloc.h"
#include "matrix_operations.h"
#include "matrix.h"
#include "libft.h"
#include <math.h>
#include "messages.h"
#include "transform.h"

static void	cylinder_calc_abc(t_inter_cy_vars *vars, t_ray *ray)
{
	vars->abc[A] = pow(ray->direction->elements[X], 2) \
				+ pow(ray->direction->elements[Z], 2);
	vars->abc[B] = 2 * ray->origin->elements[X] * ray->direction->elements[X] \
			+ 2 * ray->origin->elements[Z] * ray->direction->elements[Z];
	vars->abc[C] = pow(ray->origin->elements[X], 2) \
						+ pow(ray->origin->elements[Z], 2) - 1;
}

static void	swap(double *t0, double *t1)
{
	double	temp;

	if (*t0 > *t1)
	{
		temp = *t0;
		*t0 = *t1;
		*t1 = temp;
	}
}

static void	make_inter(t_inter_cy_vars *vars, t_shape *shape, double t)
{
	t_inter	*inter_temp;
	t_list	*item_temp;

	inter_temp = create_intersection(t, shape);
	if (!inter_temp)
	{
		show_error_method("intersect_cylinder", MERR_ALLOC_INTER);
		return ;
	}
	item_temp = ft_lstnew(inter_temp);
	if (!item_temp)
	{
		show_error_method("intersect_cylinder", MERR_CREATING_LST);
		destroy_intersection(&inter_temp);
		return ;
	}
	ft_lstadd_back(&vars->inter_list, item_temp);
}

static void	intersect_caps_cy(t_inter_cy_vars *vars, t_shape *shape, t_ray *ray)
{
	double		t;
	t_cylinder	*cy;

	cy = (t_cylinder *)shape->shape;
	if (!cy->is_closed || nearly_zero(ray->direction->elements[Y]))
		return ;
	t = (cy->minimum - ray->origin->elements[Y]) / ray->direction->elements[Y];
	if (check_cap_cylinder(ray, t))
		make_inter(vars, shape, t);
	t = (cy->maximum - ray->origin->elements[Y]) / ray->direction->elements[Y];
	if (check_cap_cylinder(ray, t))
		make_inter(vars, shape, t);
}

t_list	*intersect_cylinder(t_shape *shape, t_ray *ray_transformed)
{
	t_inter_cy_vars	vars;

	vars.status = 0;
	vars.inter_list = NULL;
	vars.cy = (t_cylinder *)shape->shape;
	cylinder_calc_abc(&vars, ray_transformed);
	if (!nearly_zero(vars.abc[A]))
	{
		vars.disc = pow(vars.abc[B], 2) - 4 * vars.abc[A] * vars.abc[C];
		if (vars.disc < 0)
			return (NULL);
		vars.t0 = (-vars.abc[B] - sqrt(vars.disc)) / (2 * vars.abc[A]);
		vars.t1 = (-vars.abc[B] + sqrt(vars.disc)) / (2 * vars.abc[A]);
		swap(&vars.t0, &vars.t1);
		vars.y0 = ray_transformed->origin->elements[Y] + \
			vars.t0 * ray_transformed->direction->elements[Y];
		vars.y1 = ray_transformed->origin->elements[Y] + \
			vars.t1 * ray_transformed->direction->elements[Y];
		if (vars.cy->minimum < vars.y0 && vars.y0 < vars.cy->maximum)
			make_inter(&vars, shape, vars.t0);
		if (vars.cy->minimum < vars.y1 && vars.y1 < vars.cy->maximum)
			make_inter(&vars, shape, vars.t1);
	}
	intersect_caps_cy(&vars, shape, ray_transformed);
	return (vars.inter_list);
}
