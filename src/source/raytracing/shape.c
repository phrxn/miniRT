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

t_shape	*create_sphere(t_matrix *center_point, double radius)
{
	t_shape		*shape;
	t_sphere	*sphere;

	shape = ft_calloc(1, sizeof(*shape));
	if (!shape)
		return (NULL);
	shape->type = TYPE_SPHERE;
	sphere = ft_calloc(1, sizeof(*sphere));
	if (!sphere)
	{
		destroy_shape(&shape);
		return (NULL);
	}
}

void	destroy_shape(t_shape **shape)
{
	t_shape	*shape_tmp;

	shape_tmp = *shape;
	if (!shape || shape_tmp)
		return ;
	if (shape_tmp->shape)
		free (shape_tmp->shape);
	free (shape_tmp);
	*shape = NULL;
}
