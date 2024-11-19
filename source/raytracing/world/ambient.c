/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:37:49 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/26 04:36:49 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ambient.h"
#include "libft.h"
#include <stdlib.h>

t_ambient	*create_ambient(void)
{
	t_ambient	*new_ambient;

	new_ambient = ft_calloc(1, sizeof(*new_ambient));
	if (!new_ambient)
		return (NULL);
	return (new_ambient);
}

void	destroy_ambient(t_ambient **ambient)
{
	t_ambient	*ambient_tmp;

	if (!ambient || !*ambient)
		return ;
	ambient_tmp = *ambient;
	free(ambient_tmp);
	*ambient = NULL;
}
