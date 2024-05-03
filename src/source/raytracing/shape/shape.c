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
#include "types.h"

static int	create_transformation_matrix(t_shape *shape)
{
	t_matrix	*transformation;
	t_uint		status;

	status = OK_MALLOC;
	transformation = matrix_create_identity_4x4();
	if(!transformation)
		status = ERR_MALLOC_SHAPE;
	shape->transformation = transformation;
	return (status);
}

int	create_shape(t_shape **shape)
{
	int			status;

	status = OK_MALLOC;
	*shape = ft_calloc(1, sizeof(**shape));
	if (!*shape)
		return ERR_MALLOC_SHAPE;
	status = create_transformation_matrix(*shape);
	if (status != OK_MALLOC)
		destroy_shape(shape);
	return (status);
}

void	destroy_shape(t_shape **shape)
{
	t_shape	*shape_tmp;

	if (!shape || !*shape)
		return ;
	shape_tmp = *shape;
	if (shape_tmp->transformation)
		destroy_matrix(&(shape_tmp->transformation));
	free(shape_tmp);
	*shape = NULL;
}
