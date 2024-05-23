/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   property_convert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:42:41 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/22 15:29:49 by dmanoel-         ###   ########.fr       */
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

int	property_to_int(t_token *token, int *result)
{
	int	status;

	if (!dict_is_a_number(token))
		return (ERR_VALUE_NOT_A_NUMBER);
	if (!dict_is_a_neg_int(token) && !dict_is_a_pos_int(token))
		return (ERR_VALUE_NOT_A_INT);
	status = OK_CONVERT;
	*result = ft_atoi_2(token->text, &status);
	return (status);
}

int	property_to_double(t_token *token, double *result)
{
	int	status;

	if (!dict_is_a_number(token))
		return (ERR_VALUE_NOT_A_NUMBER);
	if (!dict_is_a_neg_double(token) && !dict_is_a_pos_double(token))
		return (ERR_VALUE_NOT_A_DOUBLE);
	status = OK_CONVERT;
	*result = ft_atof(token->text);
	return (status);
}

int	property_xyz_to_double(t_list *token_list, double xyz[3])
{
	t_token	*token_tmp;
	int		status;

	status = OK_CONVERT;
	token_tmp = (t_token*)ft_lstget(token_list, 0)->content;
	status = property_to_double(token_tmp, &xyz[X]);
	if (status != OK_CONVERT)
		return (ERR_VALUE_X_NOT_VALID);
	token_tmp = (t_token*)ft_lstget(token_list, 2)->content;
	status = property_to_double(token_tmp, &xyz[Y]);
	if (status != OK_CONVERT)
		return (ERR_VALUE_Y_NOT_VALID);
	token_tmp = (t_token*)ft_lstget(token_list, 4)->content;
	status = property_to_double(token_tmp, &xyz[Z]);
	if (status != OK_CONVERT)
		return (ERR_VALUE_Z_NOT_VALID);
	return (status);
}

int	property_xyz_to_int(t_list *token_list, int xyz[3])
{
	t_token	*token_tmp;
	int		status;

	status = OK_CONVERT;
	token_tmp = (t_token*)ft_lstget(token_list, 0)->content;
	status = property_to_int(token_tmp, &xyz[X]);
	if (status != OK_CONVERT)
		return (ERR_VALUE_X_NOT_VALID);
	token_tmp = (t_token*)ft_lstget(token_list, 2)->content;
	status = property_to_int(token_tmp, &xyz[Y]);
	if (status != OK_CONVERT)
		return (ERR_VALUE_Y_NOT_VALID);
	token_tmp = (t_token*)ft_lstget(token_list, 4)->content;
	status = property_to_int(token_tmp, &xyz[Z]);
	if (status != OK_CONVERT)
		return (ERR_VALUE_Z_NOT_VALID);
	return (status);
}
