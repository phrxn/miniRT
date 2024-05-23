/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:29:48 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/24 16:14:52 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "values_elements.h"
# include "properties_values.h"
# include "property_convert.h"
# include "values_errors.h"
# include "array.h"

int check_y_axis(t_list *token_list)
{
	double	xyz_coordenates[3];
	double	xyz_direction[3];

	property_xyz_to_number(ft_lstget(token_list, 2), xyz_coordenates);
	property_xyz_to_number(ft_lstget(token_list, 8), xyz_direction);

	if (xyz_coordenates[X] == 0 && xyz_coordenates[Z] == 0
		&& xyz_direction[X] == 0 && xyz_direction[Z] == 0)
		return ((ERR_PROPERTY_CAMERA_AXIX_Y));
	return (OK_PROPERTY_VALUES);
}

int	values_camera(t_list *token_list)
{
	int	status;

	status = check_property_values_coor_camera(ft_lstget(token_list, 2));
	if (status != OK_PROPERTY_VALUES)
		return (status);
	status = check_property_values_direction(ft_lstget(token_list, 8));
	if (status != OK_PROPERTY_VALUES)
		return (status);
	status = check_property_values_fov(ft_lstget(token_list, 14));
	if (status != OK_PROPERTY_VALUES)
		return (status);
	status = check_y_axis(token_list);
	if (status != OK_PROPERTY_VALUES)
		return (status);
	return (OK_PROPERTY_VALUES);
}
