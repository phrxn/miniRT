/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   properties_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:59:12 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/22 14:49:13 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "properties_values.h"
#include "libft.h"
#include "token.h"
#include "array.h"
#include "property_convert.h"
#include "convert_errors.h"
#include "values_errors.h"
#include "types.h"

static int	is_color_invalid(int color)
{
	if (color < 0 || color > 255)
		return (TRUE);
	return (FALSE);
}

int check_property_values_coor(t_list *token_list)
{
	double	xyz[3];
	int		status;

	status = property_xyz_to_number(token_list, xyz);
	if (status != OK_CONVERT)
		return (ERR_PROPERTY_VALUES_COOR);
	return (OK_PROPERTY_VALUES);
}

int check_property_values_direction(t_list *token_list)
{
	double	xyz[3];
	int		status;

	status = property_xyz_to_number(token_list, xyz);
	if (status != OK_CONVERT)
		return (ERR_PROPERTY_VALUES_DIRECTION_CONVERT);
	if (xyz[X] == 0 && xyz[Y] == 0 && xyz[Z] == 0)
		return (ERR_PROPERTY_VALUES_DIRECTION_ALL_ZEROS);
	return (OK_PROPERTY_VALUES);
}

int check_property_values_color(t_list *token_list)
{
	int		xyz[3];
	int		status;

	status = property_xyz_to_int(token_list, xyz);
	if (status != OK_CONVERT)
		return (ERR_PROPERTY_VALUES_COLOR);
	if (is_color_invalid(xyz[X]) || is_color_invalid(xyz[Y])
		|| is_color_invalid(xyz[Z]))
		return (ERR_PROPERTY_VALUES_COLOR_INVALID);
	return (OK_PROPERTY_VALUES);
}

int check_property_values_fov(t_list *token_list)
{
	t_token	*token_tmp;
	int		value;
	int		status;

	token_tmp = (t_token*)ft_lstget(token_list, 0)->content;
	status = property_to_int(token_tmp, &value);
	if (status != OK_CONVERT)
		return (ERR_PROPERTY_VALUES_FOV);
	if (value < 0 || value > 180)
		return (ERR_PROPERTY_VALUES_FOV_INVALID);
	return (OK_PROPERTY_VALUES);
}
