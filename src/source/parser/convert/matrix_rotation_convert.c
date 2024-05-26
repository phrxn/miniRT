/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation_convert.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:25:58 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/26 04:33:49 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_rotation_convert.h"
#include "transformation.h"
#include "libft.h"
#include "property_convert.h"
#include "types.h"
#include "matrix.h"
#include "matrix_fill.h"
#include "matrix_operations.h"
#include <math.h>

static int	is_vector_parallel_y(t_matrix *vector3d, int positive)
{
	if (positive)
	{
		if (vector3d->elements[X] == 0 && vector3d->elements[Y] > 0
			&& vector3d->elements[Z] == 0)
			return (TRUE);
		return (FALSE);
	}
	if (vector3d->elements[X] == 0 && vector3d->elements[Y] < 0
		&& vector3d->elements[Z] == 0)
		return (TRUE);
	return (FALSE);
}

static void	start_rot_auxiliar(t_matrix *v3d, t_matrix *refe, t_matrix *cross)
{
	v3d->rows = 4;
	v3d->cols = 1;
	refe->rows = 4;
	refe->cols = 1;
	cross->rows = 4;
	cross->cols = 1;
}

static void	rotation_matrix(t_matrix *axis, double angle, t_matrix *fill)
{
	double	c;
	double	s;
	double	t;
	double	coor[3];

	c = cos(angle);
	s = sin(angle);
	t = 1.0 - c;
	coor[X] = get_element(axis, 0, 0);
	coor[Y] = get_element(axis, 1, 0);
	coor[Z] = get_element(axis, 2, 0);
	set_element(fill, 0, 0, (t * coor[X] * coor[X] + c));
	set_element(fill, 0, 1, (t * coor[X] * coor[Y] - s * coor[Z]));
	set_element(fill, 0, 2, (t * coor[X] * coor[Z] + s * coor[Y]));
	set_element(fill, 1, 0, (t * coor[X] * coor[Y] + s * coor[Z]));
	set_element(fill, 1, 1, (t * coor[Y] * coor[Y] + c));
	set_element(fill, 1, 2, (t * coor[Y] * coor[Z] - s * coor[X]));
	set_element(fill, 2, 0, (t * coor[X] * coor[Z] - s * coor[Y]));
	set_element(fill, 2, 1, (t * coor[Y] * coor[Z] + s * coor[X]));
	set_element(fill, 2, 2, (t * coor[Z] * coor[Z] + c));
}

//create rotation matrix;
void	cr(t_transformation *tt, double v3d[4], double ref[4], double cross[4])
{
	double		angle;
	double		dot_value;
	t_matrix	v3d_normalized;
	t_matrix	reference_vector;
	t_matrix	cross_product;

	start_rot_auxiliar(&v3d_normalized, &reference_vector, &cross_product);
	v3d_normalized.elements = v3d;
	reference_vector.elements = ref;
	cross_product.elements = cross;
	matrix_normalization(&v3d_normalized, &v3d_normalized);
	matrix_normalization(&v3d_normalized, &v3d_normalized);
	if (is_vector_parallel_y(&v3d_normalized, TRUE))
		return ;
	if (is_vector_parallel_y(&v3d_normalized, FALSE))
	{
		matrix_fill_rot_z(tt->rotation, M_PI);
		return ;
	}
	matrix_cross(&reference_vector, &v3d_normalized, &cross_product);
	matrix_normalization(&cross_product, &cross_product);
	matrix_dot(&reference_vector, &v3d_normalized, &dot_value);
	angle = acos(dot_value);
	rotation_matrix(&cross_product, angle, tt->rotation);
}

void	tokens_to_rotation(t_transformation *tt, double xyz_double[3])
{
	double	v3d_normalized[4];
	double	reference_vector[4];
	double	cross_product[4];

	reference_vector[X] = 0;
	reference_vector[Y] = 1;
	reference_vector[Z] = 0;
	reference_vector[W] = 0;
	v3d_normalized[X] = xyz_double[X];
	v3d_normalized[Y] = xyz_double[Y];
	v3d_normalized[Z] = xyz_double[Z];
	v3d_normalized[W] = 0;
	cr(tt, v3d_normalized, reference_vector, cross_product);
}
