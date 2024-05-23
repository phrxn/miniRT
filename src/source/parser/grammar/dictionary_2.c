/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:20:04 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/16 14:28:35 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

BOOL dict_is_a_separator_value(t_token *token)
{
	if (token->type == separator_value)
		return (TRUE);
	return (FALSE);
}

BOOL dict_is_a_separator_property(t_token *token)
{
	if (token->type == separator_property)
		return (TRUE);
	return (FALSE);
}

BOOL dict_is_a_eol(t_token *token)
{
	if (token->type == eol)
		return (TRUE);
	return (FALSE);
}

BOOL dict_is_a_number(t_token *token)
{
	if (token->type == pos_int || token->type == neg_int ||
		token->type == pos_double || token->type == neg_double)
		return (TRUE);
	return (FALSE);
}