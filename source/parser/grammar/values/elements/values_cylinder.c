/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:29:48 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/26 04:52:04 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "values_elements.h"
#include "properties_values.h"
#include "values_errors.h"
#include "array.h"

int	values_cylinder(t_list *token_list)
{
	int	status;

	status = check_property_values_coor(ft_lstget(token_list, 2));
	if (status != OK_PROPERTY_VALUES)
		return (status);
	status = check_property_values_direction(ft_lstget(token_list, 8));
	if (status != OK_PROPERTY_VALUES)
		return (status);
	status = check_property_values_diam(ft_lstget(token_list, 14));
	if (status != OK_PROPERTY_VALUES)
		return (status);
	status = check_property_values_height(ft_lstget(token_list, 16));
	if (status != OK_PROPERTY_VALUES)
		return (status);
	status = check_property_values_color(ft_lstget(token_list, 18));
	if (status != OK_PROPERTY_VALUES)
		return (status);
	return (OK_PROPERTY_VALUES);
}
