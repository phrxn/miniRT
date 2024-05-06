/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:07:24 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/06 20:39:17 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "intersect_sphere.h"
#include "messages.h"

t_list	*intersect(t_shape *shape, t_ray *ray_transformed)
{
	if (shape->type == TYPE_SPHERE)
		return (intersect_sphere(shape, ray_transformed));
	else
		show_error_method("intersect", MERR_INVALID_OBJ_TYPE);
	return (NULL);
}
