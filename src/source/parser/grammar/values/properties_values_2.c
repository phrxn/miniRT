/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   properties_values_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:59:12 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/26 04:48:16 by gacalaza         ###   ########.fr       */
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

int	check_property_values_radio(t_list *token_list)
{
	t_token	*token_tmp;
	double	radio_value;
	int		status;

	token_tmp = (t_token *)ft_lstget(token_list, 0)->content;
	status = property_to_number(token_tmp, &radio_value);
	if (status != OK_PROPERTY_VALUES)
		return (ERR_PROPERTY_VALUES_RADIO);
	if (radio_value < 0 || radio_value > 1)
		return (ERR_PROPERTY_VALUES_RADIO_INVALID);
	return (OK_PROPERTY_VALUES);
}

int	check_property_values_diam(t_list *token_list)
{
	t_token	*token_tmp;
	double	diameter;
	int		status;

	token_tmp = (t_token *)ft_lstget(token_list, 0)->content;
	status = property_to_number(token_tmp, &diameter);
	if (status != OK_PROPERTY_VALUES)
		return (ERR_PROPERTY_VALUES_DIAM);
	if (diameter <= 0.0)
		return (ERR_PROPERTY_VALUES_DIAM_INVALID);
	return (OK_PROPERTY_VALUES);
}

int	check_property_values_height(t_list *token_list)
{
	t_token	*token_tmp;
	int		status;
	double	height;

	token_tmp = (t_token *)ft_lstget(token_list, 0)->content;
	status = property_to_number(token_tmp, &height);
	if (status != OK_PROPERTY_VALUES)
		return (ERR_PROPERTY_VALUES_HEIGHT);
	if (height <= 0.0)
		return (ERR_PROPERTY_VALUES_HEIGHT_INVALID);
	return (OK_PROPERTY_VALUES);
}

int	check_property_values_coor_camera(t_list *token_list)
{
	double	xyz[3];
	int		status;

	status = property_xyz_to_number(token_list, xyz);
	if (status != OK_CONVERT)
		return (ERR_PROPERTY_VALUES_COOR);
	if (xyz[X] == 0.0 && xyz[Y] == 0.0 && xyz[Z] == 0.0)
		return (ERR_PROPERTY_VALUES_COOR_CAMERA);
	return (OK_PROPERTY_VALUES);
}
