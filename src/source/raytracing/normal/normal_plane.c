/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 01:19:33 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/26 04:26:12 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "normal_plane.h"
#include "matrix.h"
#include "shape.h"
#include "matrix_alloc.h"

t_matrix	*normal_at_plane(t_shape *shape, t_matrix *point)
{
	t_matrix	*local_normal;

	(void)shape;
	(void)point;
	local_normal = matrix_create_vector(0, 1, 0);
	return (local_normal);
}
