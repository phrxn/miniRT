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



#include <stdio.h>


/**
 * prepared_line - prepare line to tokenizer
 * @line_readed: line to prepare
 *
 * 1) Remove initial and final spaces
 * 2) change \n to \0 (if exist) in the line
 *
 * Return:
 * 	On failure:
 * 		return NULL (if the line is empty or totally filled with spaces)
 *  On sucessfull:
 * 		a malloced line with \n and "trimed"
*/
STATIC char	*prepared_line(const char *line_readed)
{
	char	*line_prepared;
	char	*line_readed_cpy;
	size_t	line_size;

	if (!line_readed)
		return (NULL);
	line_size = ft_strlen(line_readed);
	if (line_size == 0)
		return (NULL);
	line_readed_cpy = ft_strdup(line_readed);
	if (!line_readed_cpy)
		return (NULL);
	if (line_readed_cpy[line_size - 1] == '\n')
		line_readed_cpy[line_size - 1] = '\0';
	line_prepared = ft_strtrim(line_readed_cpy, " ");
	free(line_readed_cpy);
	if (line_prepared[0] == '\0')
	{
		free(line_prepared);
		return (NULL);
	}
	return (line_prepared);
}

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
 * Create a token list to a not
 *
 * Return:
 *	On success:
 *		the token list
 *	On failure:
 *		NULL (memory alloc error!)
 */
STATIC t_list	*line_create_tokens(const char *line_to_split)
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

t_list	*file_create_tokens(int fd)
{
	t_list	*token_list;
	t_list	*token_tmp;
	char	*line_readed;
	char	*line_treated;

	token_list = NULL;
	line_treated = NULL;
	while (1)
	{
		if (line_treated)
			free(line_treated);
		line_readed = get_next_line(fd);
		if (!line_readed)
			break ;
		line_treated = prepared_line(line_readed);
		free(line_readed);
		if (!line_treated)
			continue ;
		token_tmp = line_create_tokens(line_treated);
		ft_lstadd_back(&token_list, token_tmp);
	}
	return (token_list);
}