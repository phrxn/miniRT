/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_ambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:06:55 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/20 16:10:26 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_elements.h"
#include "dictionary.h"
#include "libft.h"
#include "properties_syntax.h"
#include "syntax_errors.h"
#include "token.h"
#include "array.h"

int	syntax_ambient(t_list *token_list)
{
	t_token	*token_tmp;

	if (check_property_syntax_identifier(ft_lstget(token_list, 0)))
		return (ERR_PROPERTY_IDENTIFIER);
	token_tmp = (t_token*)ft_lstget(token_list, 1)->content;
	if (!dict_is_a_separator_property(token_tmp))
		return (ERR_SYNTAX);
	if (check_property_syntax_radio(ft_lstget(token_list, 2)))
		return (ERR_PROPERTY_RADIO);
	token_tmp = (t_token*)ft_lstget(token_list, 3)->content;
	if (!dict_is_a_separator_property(token_tmp))
		return (ERR_SYNTAX);
	if (check_property_syntax_color(ft_lstget(token_list, 4)))
		return (ERR_PROPERTY_COLOR);
	token_tmp = (t_token*)ft_lstget(token_list, 9)->content;
	if (!dict_is_a_eol(token_tmp))
		return (ERR_PROPERTY_EOL);
	return (OK_SYNTAX);
}
