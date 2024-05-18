/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:41:10 by gacalaza          #+#    #+#             */
/*   Updated: 2024/04/23 22:26:10 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "matrix.h"
#include "libft.h"
#include "messages.h"
#include "matrix_alloc.h"
#include "matrix_utils.h"
#include "types.h"

t_shape	*create_shape(int type)
{
	t_shape	*shape;

	shape = ft_calloc(1, sizeof(*shape));
	if (!shape)
		return (NULL);
	shape->type = type;
	shape->transformation = matrix_create_identity_4x4();
	shape->transformation_inv = matrix_create_identity_4x4();
	if (!shape->transformation)
	{
		free(shape);
		return (NULL);
	}
	if (type == TYPE_SPHERE)
		shape->shape = create_sphere();
	if (!shape->shape)
		destroy_shape(&shape);
	return (shape);
}

void	destroy_shape(t_shape **shape)
{
	t_shape	*shape_tmp;

	if (!shape || !*shape)
		return ;
	shape_tmp = *shape;
	if (shape_tmp->transformation)
		destroy_matrix(&shape_tmp->transformation);
	if (shape_tmp->transformation_inv)
		destroy_matrix(&shape_tmp->transformation_inv);
	if (shape_tmp->shape)
	{
		if (shape_tmp->type == TYPE_SPHERE)
			destroy_sphere((t_sphere**)&shape_tmp->shape);
	}
	free(shape_tmp);
	*shape = NULL;
}

void	destroy_shape2(void *shape)
{
	t_shape	*shape_tmp;

	shape_tmp = (t_shape *)shape;
	destroy_shape(&shape_tmp);
}


t_shape	*create_shape_copy(t_shape	*shape)
{
	t_shape	*new_shape;

	new_shape = create_shape(shape->type);
	if (!new_shape)
		return (NULL);
	new_shape->id = shape->id;
	material_copy(&shape->material, &new_shape->material);
	matrix_copy(shape->transformation, new_shape->transformation);
	new_shape->type = shape->type;
	if (shape->type == TYPE_SPHERE)
		copy_sphere(shape->shape, new_shape->shape);
	return (new_shape);
}