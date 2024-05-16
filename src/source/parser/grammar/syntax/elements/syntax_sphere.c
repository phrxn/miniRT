/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:07:09 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/20 16:10:41 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_elements.h"
#include "dictionary.h"
#include "libft.h"
#include "properties_syntax.h"
#include "syntax_errors.h"
#include "token.h"
#include "array.h"

int	syntax_sphere(t_list *token_list)
{
	t_token	*token_tmp;

	if (check_property_syntax_identifier(ft_lstget(token_list, 0)))
		return (ERR_PROPERTY_IDENTIFIER);
	token_tmp = (t_token*)ft_lstget(token_list, 1)->content;
	if (!dict_is_a_separator_property(token_tmp))
		return (ERR_SYNTAX);
	if (check_property_syntax_coor(ft_lstget(token_list, 2)))
		return (ERR_PROPERTY_COOR);
	token_tmp = (t_token*)ft_lstget(token_list, 7)->content;
	if (!dict_is_a_separator_property(token_tmp))
		return (ERR_SYNTAX);
	if (check_property_syntax_diam(ft_lstget(token_list, 8)))
		return (ERR_PROPERTY_DIAM);
	token_tmp = (t_token*)ft_lstget(token_list, 9)->content;
	if (!dict_is_a_separator_property(token_tmp))
		return (ERR_SYNTAX);
	if (check_property_syntax_color(ft_lstget(token_list, 10)))
		return (ERR_PROPERTY_COLOR);
	token_tmp = (t_token*)ft_lstget(token_list, 15)->content;
	if (!dict_is_a_eol(token_tmp))
		return (ERR_PROPERTY_EOL);
	return (OK_SYNTAX);
}