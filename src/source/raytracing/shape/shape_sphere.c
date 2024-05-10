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
#include "matrix_utils.h"
#include "types.h"


t_sphere	*create_sphere()
{
	t_sphere	*sphere;

	sphere = ft_calloc(1, sizeof(*sphere));
	if (!sphere)
		return (NULL);
	sphere->center = matrix_create_point(0, 0, 0);
	sphere->radius = 1;
	if (!sphere->center)
	{
		destroy_sphere(&sphere);
		return (NULL);
	}
	return (sphere);
}

void	destroy_sphere(t_sphere **sphere)
{
	t_sphere	*sphere_tmp;

	if (!sphere || !*sphere)
		return ;
	sphere_tmp = *sphere;
	if (sphere_tmp->center)
		destroy_matrix(&sphere_tmp->center);
	free(sphere_tmp);
	*sphere = NULL;
}

void	copy_sphere(t_sphere *from, t_sphere *to)
{
	matrix_copy(from->center, to->center);
	to->radius = from->radius;
}