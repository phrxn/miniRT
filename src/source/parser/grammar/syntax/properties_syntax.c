/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   properties_syntax.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:39:17 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/25 03:22:16 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "properties_syntax.h"
# include "array.h"
# include "libft.h"
# include "syntax_errors.h"
# include "token.h"
# include "dictionary.h"

int check_property_syntax_coor(t_list *token_list)
{
	t_token	*token_tmp;

	token_tmp = (t_token*)ft_lstget(token_list, 0)->content;
	if (!dict_is_a_number(token_tmp))
		return (ERR_PROPERTY_COOR);
	token_tmp = (t_token*)ft_lstget(token_list, 1)->content;
	if (!dict_is_a_separator_value(token_tmp))
		return (ERR_PROPERTY_COOR);
	token_tmp = (t_token*)ft_lstget(token_list, 2)->content;
	if (!dict_is_a_number(token_tmp))
		return (ERR_PROPERTY_COOR);
	token_tmp = (t_token*)ft_lstget(token_list, 3)->content;
	if (!dict_is_a_separator_value(token_tmp))
		return (ERR_PROPERTY_COOR);
	token_tmp = (t_token*)ft_lstget(token_list, 4)->content;
	if (!dict_is_a_number(token_tmp))
		return (ERR_PROPERTY_COOR);
	return (OK_SYNTAX);
}

int check_property_syntax_direction(t_list *token_list)
{
	t_token	*token_tmp;

	token_tmp = (t_token*)ft_lstget(token_list, 0)->content;
	if (!dict_is_a_number(token_tmp))
		return (ERR_PROPERTY_DIRECTION);
	token_tmp = (t_token*)ft_lstget(token_list, 1)->content;
	if (!dict_is_a_separator_value(token_tmp))
		return (ERR_PROPERTY_DIRECTION);
	token_tmp = (t_token*)ft_lstget(token_list, 2)->content;
	if (!dict_is_a_number(token_tmp))
		return (ERR_PROPERTY_DIRECTION);
	token_tmp = (t_token*)ft_lstget(token_list, 3)->content;
	if (!dict_is_a_separator_value(token_tmp))
		return (ERR_PROPERTY_DIRECTION);
	token_tmp = (t_token*)ft_lstget(token_list, 4)->content;
	if (!dict_is_a_number(token_tmp))
		return (ERR_PROPERTY_DIRECTION);
	return (OK_SYNTAX);
}

int check_property_syntax_color(t_list *token_list)
{
	t_token	*token_tmp;

	token_tmp = (t_token*)ft_lstget(token_list, 0)->content;
	if (!dict_is_a_pos_int(token_tmp))
		return (ERR_PROPERTY_COLOR);
	token_tmp = (t_token*)ft_lstget(token_list, 1)->content;
	if (!dict_is_a_separator_value(token_tmp))
		return (ERR_PROPERTY_COLOR);
	token_tmp = (t_token*)ft_lstget(token_list, 2)->content;
	if (!dict_is_a_pos_int(token_tmp))
		return (ERR_PROPERTY_COLOR);
	token_tmp = (t_token*)ft_lstget(token_list, 3)->content;
	if (!dict_is_a_separator_value(token_tmp))
		return (ERR_PROPERTY_COLOR);
	token_tmp = (t_token*)ft_lstget(token_list, 4)->content;
	if (!dict_is_a_pos_int(token_tmp))
		return (ERR_PROPERTY_COLOR);
	return (OK_SYNTAX);
}

int check_property_syntax_fov(t_list *token_list)
{
	t_token	*token_tmp;

	token_tmp = (t_token*)ft_lstget(token_list, 0)->content;
	if (!dict_is_a_pos_int(token_tmp))
		return (ERR_PROPERTY_FOV);
	return (OK_SYNTAX);
}

int check_property_syntax_radio(t_list *token_list)
{
	t_token	*token_tmp;

	token_tmp = (t_token*)ft_lstget(token_list, 0)->content;
	if (!dict_is_a_pos_double(token_tmp) && !dict_is_a_pos_int(token_tmp))
		return (ERR_PROPERTY_RADIO);
	return (OK_SYNTAX);
}
