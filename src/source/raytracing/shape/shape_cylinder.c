/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:09:37 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/19 20:25:41 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "libft.h"

t_cylinder	*create_cylinder(void)
{
	t_cylinder	*cylinder;

	cylinder = ft_calloc(1, sizeof(*cylinder));
	if (!cylinder)
		return (NULL);
	cylinder->is_closed = TRUE;
	cylinder->minimum = -1;
	cylinder->maximum = 1;
	return (cylinder);
}

void	destroy_cylinder(t_cylinder **cylinder)
{
	t_cylinder	*cylinder_tmp;

	if (!cylinder || !*cylinder)
		return ;
	cylinder_tmp = *cylinder;
	free(cylinder_tmp);
	*cylinder = NULL;
}

void	copy_cylinder(t_cylinder *from, t_cylinder *to)
{
	to->is_closed = from->is_closed;
	to->minimum = from->minimum;
	to->maximum = from->maximum;
}
