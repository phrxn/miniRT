/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:20:14 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/24 19:55:02 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select_element.h"
#include "libft.h"
#include "token.h"

t_element_type	select_element_type(t_token* token_identifier)
{
	if (ft_strncmp("A", token_identifier->text, ft_strlen("A")) == 0)
		return (ambient);
	if (ft_strncmp("C", token_identifier->text, ft_strlen("C")) == 0)
		return (camera);
	if (ft_strncmp("L", token_identifier->text, ft_strlen("L")) == 0)
		return (light);
	if (ft_strncmp("sp", token_identifier->text, ft_strlen("sp")) == 0)
		return (sphere);
	if (ft_strncmp("pl", token_identifier->text, ft_strlen("pl")) == 0)
		return (plane);
	if (ft_strncmp("cy", token_identifier->text, ft_strlen("cy")) == 0)
		return (cylinder);
	return (not_exist);
}

t_element_type	get_element_type(t_list *token_list)
{
	t_token	*token_identifier;

	token_identifier = (t_token *)token_list->content;
	return (select_element_type(token_identifier));
}