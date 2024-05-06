/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:42:27 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/02 15:42:27 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "matrix.h"
#include "libft.h"
#include "messages.h"
#include "matrix_alloc.h"
#include "types.h"

static int	create_center(t_sphere *sphere)
{
	t_matrix	*center;
	int			status;

	status = OK_MALLOC;
	center = matrix_create_point(0, 0, 0);
	if (!center)
		status = ERR_MALLOC_SHAPE;
	sphere->center = center;
	return (status);
}

t_shape	*create_sphere(t_uint id)
{
	t_shape		*shape;
	t_sphere	*sphere;
	int			status;

	status = create_shape(&shape);
	if (status != OK_MALLOC)
		return (NULL);
	sphere = ft_calloc(1, sizeof(*sphere));
	if (!sphere)
		status = ERR_MALLOC_SHAPE;
	if (status == OK_MALLOC)
		status = create_center(sphere);
	if (status == OK_MALLOC)
		sphere->radius = 1;
	if (status == OK_MALLOC)
	{
		shape->id = id;
		shape->type = TYPE_SPHERE;
		shape->shape = sphere;
	}
	if (status != OK_MALLOC)
		destroy_sphere(&shape);
	return (shape);
}

void	destroy_sphere(t_shape **shape)
{
	t_sphere	*sphere;
	t_shape		*shape_tmp;

	if (!shape || !*shape)
		return ;
	shape_tmp = *shape;
	sphere = (t_sphere *)shape_tmp->shape;
	if (sphere && sphere->center)
		destroy_matrix(&(sphere->center));
	free(sphere);
	destroy_shape(shape);
}
