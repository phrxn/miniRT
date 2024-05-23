/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   property_convert_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:42:41 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/22 14:27:09 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "property_convert.h"
#include "libft.h"
#include "dictionary.h"
#include "convert_errors.h"
#include "ft_atof.h"
#include "ft_atoi_2.h"
#include "array.h"
#include "matrix.h"

int	property_to_number(t_token *token, double *result)
{
	if (!dict_is_a_number(token))
		return (ERR_VALUE_NOT_A_NUMBER);
	*result = ft_atof(token->text);
	return (OK_CONVERT);
}

int	property_xyz_to_number(t_list *token_list, double xyz[3])
{
	t_token	*token_tmp;
	int		status;

	status = OK_CONVERT;
	token_tmp = (t_token*)ft_lstget(token_list, 0)->content;
	status = property_to_number(token_tmp, &xyz[X]);
	if (status != OK_CONVERT)
		return (ERR_VALUE_X_NOT_VALID);
	token_tmp = (t_token*)ft_lstget(token_list, 2)->content;
	status = property_to_number(token_tmp, &xyz[Y]);
	if (status != OK_CONVERT)
		return (ERR_VALUE_Y_NOT_VALID);
	token_tmp = (t_token*)ft_lstget(token_list, 4)->content;
	status = property_to_number(token_tmp, &xyz[Z]);
	if (status != OK_CONVERT)
		return (ERR_VALUE_Z_NOT_VALID);
	return (status);
}
