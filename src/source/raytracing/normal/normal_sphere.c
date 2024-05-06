/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:34:49 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/04 19:30:07 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "normal_sphere.h"
#include "normal.h"
#include "matrix.h"
#include "shape.h"
#include "matrix_alloc.h"
#include "matrix_operations.h"
#include "messages.h"

t_matrix	*normal_at_sphere(t_shape *shape, t_matrix *point)
{
	t_matrix	*local_normal;
	t_sphere	*sphere;

	sphere = (t_sphere *)shape->shape;
	local_normal = matrix_create_subtraction(point, sphere->center);
	return (local_normal);
}
