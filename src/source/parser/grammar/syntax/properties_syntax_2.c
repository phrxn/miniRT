/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   properties_syntax_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:39:29 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/25 03:22:44 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "properties_syntax.h"
# include "array.h"
# include "libft.h"
# include "syntax_errors.h"
# include "token.h"
# include "dictionary.h"

int check_property_syntax_diam(t_list *token_list)
{
	t_token	*token_tmp;

	token_tmp = (t_token*)ft_lstget(token_list, 0)->content;
	if (!dict_is_a_pos_double(token_tmp) && !dict_is_a_pos_int(token_tmp))
		return (ERR_PROPERTY_DIAM);
	return (OK_SYNTAX);
}

int check_property_syntax_height(t_list *token_list)
{
	t_token	*token_tmp;

	token_tmp = (t_token*)ft_lstget(token_list, 0)->content;
	if (!dict_is_a_pos_double(token_tmp) && !dict_is_a_pos_int(token_tmp))
		return (ERR_PROPERTY_HEIGHT);
	return (OK_SYNTAX);
}

int check_property_syntax_identifier(t_list *token_list)
{
	t_token	*token_tmp;

	token_tmp = (t_token*)ft_lstget(token_list, 0)->content;

	if (!dict_is_a_identifier(token_tmp))
		return (ERR_PROPERTY_IDENTIFIER);
	return (OK_SYNTAX);
}
