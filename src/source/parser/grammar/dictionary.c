/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:19:35 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/16 14:22:26 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"
#include "token.h"

BOOL dict_is_a_identifier(t_token *token)
{
	if (token->type == identifier)
		return (TRUE);
	return (FALSE);
}

BOOL dict_is_a_pos_int(t_token *token)
{
	if (token->type == pos_int)
		return (TRUE);
	return (FALSE);
}

BOOL dict_is_a_neg_int(t_token *token)
{
	if (token->type == neg_int)
		return (TRUE);
	return (FALSE);
}

BOOL dict_is_a_pos_double(t_token *token)
{
	if (token->type == pos_double)
		return (TRUE);
	return (FALSE);
}

BOOL dict_is_a_neg_double(t_token *token)
{
	if (token->type == neg_double)
		return (TRUE);
	return (FALSE);
}
