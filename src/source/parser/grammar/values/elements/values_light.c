/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:29:48 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/26 04:51:13 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "values_elements.h"
#include "properties_values.h"
#include "values_errors.h"
#include "array.h"

int	values_light(t_list *token_list)
{
	int	status;

	status = check_property_values_coor(ft_lstget(token_list, 2));
	if (status != OK_PROPERTY_VALUES)
		return (status);
	status = check_property_values_radio(ft_lstget(token_list, 8));
	if (status != OK_PROPERTY_VALUES)
		return (status);
	status = check_property_values_color(ft_lstget(token_list, 10));
	if (status != OK_PROPERTY_VALUES)
		return (status);
	return (OK_PROPERTY_VALUES);
}
