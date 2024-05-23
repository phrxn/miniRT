/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:06:58 by dmanoel-          #+#    #+#             */
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

static int syntax_camera2(t_list *token_list)
{
	t_token	*token_tmp;

	token_tmp = (t_token*)ft_lstget(token_list, 15)->content;
	if (!dict_is_a_eol(token_tmp))
		return (ERR_PROPERTY_EOL);
	return (OK_SYNTAX);
}

int	syntax_camera(t_list *token_list)
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
	if (check_property_syntax_direction(ft_lstget(token_list, 8)))
		return (ERR_PROPERTY_DIRECTION);
	token_tmp = (t_token*)ft_lstget(token_list, 13)->content;
	if (!dict_is_a_separator_property(token_tmp))
		return (ERR_SYNTAX);
	if (check_property_syntax_fov(ft_lstget(token_list, 14)))
		return (ERR_PROPERTY_FOV);
	return (syntax_camera2(token_list));
}
