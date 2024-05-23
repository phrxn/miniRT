/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:29:48 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/22 16:07:30 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "values_elements.h"
# include "properties_values.h"
# include "values_errors.h"
# include "array.h"

int	values_sphere(t_list *token_list)
{
	int	status;

	status = check_property_values_coor(ft_lstget(token_list, 2));
	if (status != OK_PROPERTY_VALUES)
		return (status);
	status = check_property_values_diam(ft_lstget(token_list, 8));
	if (status != OK_PROPERTY_VALUES)
		return (status);
	status = check_property_values_color(ft_lstget(token_list, 10));
	if (status != OK_PROPERTY_VALUES)
		return (status);
	return (OK_PROPERTY_VALUES);
}
