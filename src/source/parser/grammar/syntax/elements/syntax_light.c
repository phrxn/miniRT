/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:07:03 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/26 04:41:22 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_elements.h"
#include "dictionary.h"
#include "libft.h"
#include "properties_syntax.h"
#include "syntax_errors.h"
#include "token.h"
#include "array.h"

static int	syntax_light2(t_list *token_list)
{
	t_token	*token_tmp;

	token_tmp = (t_token *)ft_lstget(token_list, 9)->content;
	if (!dict_is_a_separator_property(token_tmp))
		return (ERR_SYNTAX);
	if (check_property_syntax_color(ft_lstget(token_list, 10)))
		return (ERR_PROPERTY_COLOR);
	token_tmp = (t_token *)ft_lstget(token_list, 15)->content;
	if (!dict_is_a_eol(token_tmp))
		return (ERR_PROPERTY_EOL);
	return (OK_SYNTAX);
}

int	syntax_light(t_list *token_list)
{
	t_token	*token_tmp;

	if (check_property_syntax_identifier(ft_lstget(token_list, 0)))
		return (ERR_PROPERTY_IDENTIFIER);
	token_tmp = (t_token *)ft_lstget(token_list, 1)->content;
	if (!dict_is_a_separator_property(token_tmp))
		return (ERR_SYNTAX);
	if (check_property_syntax_coor(ft_lstget(token_list, 2)))
		return (ERR_PROPERTY_COOR);
	token_tmp = (t_token *)ft_lstget(token_list, 7)->content;
	if (!dict_is_a_separator_property(token_tmp))
		return (ERR_SYNTAX);
	if (check_property_syntax_radio(ft_lstget(token_list, 8)))
		return (ERR_PROPERTY_RADIO);
	return (syntax_light2(token_list));
}
