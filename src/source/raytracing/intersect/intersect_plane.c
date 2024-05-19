/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:16:11 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/19 02:43:07 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect_plane.h"
#include "intersect.h"
#include "intersect_utils.h"
#include "types.h"
#include "messages.h"
#include <math.h>


static t_list	*make_lst(t_inter *i0, int *status)
{
	t_list	*item1;

	item1 = ft_lstnew(i0);
	if (!item1)
		*status = 1;
	if (*status)
	{
		if (item1)
			free(item1);
		return (NULL);
	}
	return (item1);
}

static t_list	*make_inter(double t1, t_shape *shape, int *status)
{
	t_inter	*i0;
	t_list	*item1;

	*status = 0;
	i0 = create_intersection(t1, shape);
	if (!i0)
		*status = 1;
	if (!*status)
		item1 = make_lst(i0, status);
	if (*status)
	{
		if (i0)
			destroy_intersection(&i0);
		show_error_method("intersect_plane", MERR_INTER_MALLOC);
		return (NULL);
	}
	return (item1);
}

t_list	*intersect_plane(t_shape *shape, t_ray *ray_transformed)
{
	double	t;
	int		status;

	status = 0;
	if (fabs(ray_transformed->direction->elements[Y]) < EPSILON)
		return (NULL);
	t = -ray_transformed->origin->elements[Y]
		/ ray_transformed->direction->elements[Y];
	return (make_inter(t, shape, &status));
}