/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:05:29 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/06 15:05:29 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "token.h"
#include "peek.h"
#include "libft.h"
#include "types.h"
#include <stdlib.h>

/**
 * get_token - create a token
 * @stream:	a structure with the list of tokens and other information that will
 * 			be manipulated in the creation of the token.
 *
 * Return:
 * 	 On success:
 * 		new token
 *	 On failure:
 *		NULL (memory alloc error!)
*/
static t_token	*get_token(t_stream *stream, char c)
{
	if (peek(c) == number || peek(c) == signal_pos)
		return (token_number_positive(stream));
	if (peek(c) == signal_neg)
		return (token_number_negative(stream));
	if (peek(c) == space)
		return (token_separator_property(stream));
	if (peek(c) == comma)
		return (token_separator_value(stream));
	if (peek(c) == end_line)
		return (token_eol(stream));
	return (token_identifier(stream));
}

/**
 * tokenizer - get a new token and add it to the end of the token list.
 * @stream:		the structure that is holding the string information during
 * 				tokenization.
 * @token_list: the token list to add new token
 * @c:			the current char in the string
 *
 * Return:
 * 	On success:
 * 		0 is returned
 * 	On failure:
 * 		1 is returned (malloc error!)
*/
static int	tokenizer(t_stream *stream, t_list **token_list, char c)
{
	t_token	*new_token;
	t_list	*new_list_item;

	new_token = get_token(stream, c);
	if (!new_token)
		return (1);
	new_list_item = ft_lstnew(new_token);
	if (!new_list_item)
	{
		destroy_token(&new_token);
		return (1);
	}
	ft_lstadd_back(token_list, new_list_item);
	return (0);
}

/**
 * line_create_tokens - create a token list.
 * @line_to_split:	line that will be used to create the tokens
 * 					(cannot be empty)
 *
 * Create a token list for a non-empty, non-blank and already trimmed line.
 *
 * Return:
 *	On success:
 *		the token list
 *	On failure:
 *		NULL (memory alloc error!)
 */
t_list	*line_create_tokens(const char *line_to_split)
{
	t_stream	characters_stream;
	char		current_char;
	t_list		*token_list;

	characters_stream.line = line_to_split;
	characters_stream.index = 0;
	token_list = NULL;
	current_char = characters_stream.line[characters_stream.index];
	while (current_char)
	{
		if (tokenizer(&characters_stream, &token_list, current_char))
		{
			ft_lstclear(&token_list, destroy_token2);
			return (NULL);
		}
		current_char = characters_stream.line[characters_stream.index];
	}
	if (tokenizer(&characters_stream, &token_list, '\0'))
	{
		ft_lstclear(&token_list, destroy_token2);
		return (NULL);
	}
	return (token_list);
}
