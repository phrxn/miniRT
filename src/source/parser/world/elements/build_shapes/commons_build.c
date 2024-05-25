/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commons_build.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 02:33:42 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/25 02:50:02 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons_build.h"

#include "build_element.h"
#include "build_world.h"
#include "property_convert.h"
#include "convert_errors.h"
#include "array.h"
#include "matrix_fill.h"
#include "material.h"
#include "matrix_operations.h"
#include "matrix_utils.h"

static void	set_material_color(t_shape *shape, double color[3])
{
	double	red;
	double	green;
	double	blue;

	red = color_int_to_double(color[RED]);
	green = color_int_to_double(color[GREEN]);
	blue = color_int_to_double(color[BLUE]);
	fill_color(&shape->material.color, red, green, blue);
}

int	start_shape(t_shape *shape, t_transformation *transf, double color[3])
{
	int	status;

	fill_material(&shape->material);
	status = make_transformation(transf);
	if (status != OK_OPERATION)
	{
		destroy_shape(&shape);
		return (ERR_BUILD_ELEMENT_MAKE_TRANSF_MATRIX);
	}
	matrix_copy(transf->transformation, shape->transformation);
	matrix_copy(transf->transformation_inv, shape->transformation_inv);
	set_material_color(shape, color);
	return (OK_BUILD_ELEMENT);
}
