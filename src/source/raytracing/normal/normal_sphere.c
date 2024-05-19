/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:34:49 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/19 01:15:47 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "normal_sphere.h"
#include "matrix.h"
#include "shape.h"
#include "matrix_alloc.h"

t_matrix	*normal_at_sphere(t_shape *shape, t_matrix *point)
{
	t_matrix	*local_normal;
	t_sphere	*sphere;

	sphere = (t_sphere *)shape->shape;
	local_normal = matrix_create_subtraction(point, sphere->center);
	return (local_normal);
}
