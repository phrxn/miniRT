/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 04:32:50 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/26 04:35:04 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "color.h"
#include "libft.h"
#include "matrix_alloc.h"
#include <stdlib.h>

t_light	*create_light(t_color *color, double x, double y, double z)
{
	t_light	*new_light;

	new_light = ft_calloc(1, sizeof(*new_light));
	if (!new_light)
		return (NULL);
	new_light->position = matrix_create_point(x, y, z);
	if (!new_light->position)
	{
		destroy_light(&new_light);
		return (NULL);
	}
	fill_color(&new_light->intensity, color->red, color->green, color->blue);
	return (new_light);
}

void	destroy_light(t_light **light)
{
	t_light	*light_tmp;

	if (!light || !*light)
		return ;
	light_tmp = *light;
	if (light_tmp->position)
		destroy_matrix(&light_tmp->position);
	free(light_tmp);
	*light = NULL;
}

void	destroy_light2(void *del)
{
	t_light	*light_tmp;

	light_tmp = (t_light *)del;
	if (!light_tmp)
		return ;
	destroy_light(&light_tmp);
}
