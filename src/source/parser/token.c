/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:09:24 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/10 15:53:30 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "lexer.h"
#include "libft.h"
#include "types.h"

#include <stdlib.h>

/**
 * token_create - create a new token
 * @text:	the pointer to token text
 * @type:	the token type
 *
 * Return:
 * 	On success:
 * 		a new malloc token
 * 	On failure:
 * 		NULL is returned
*/
t_token	*create_token(char *text, t_token_type type)
{
	t_token	*new_token;

	new_token = ft_calloc(1, sizeof(*new_token));
	if (!new_token)
		return (NULL);
	new_token->type = type;
	new_token->text = text;
	return (new_token);
}

/**
 * token_destroy - frees the memory of the token structure and all its members.
*/
void	destroy_token(t_token **token_free)
{
	t_token	*token_tmp;

	if (!token_free || !*token_free)
		return ;
	token_tmp = *token_free;
	if (token_tmp->text)
		free(token_tmp->text);
	free(token_tmp);
	*token_free = NULL;
}

/**
 * token_destroy - frees the memory of the token structure and all its members.
*/
void	destroy_token2(void *token)
{
	t_token	*token_free;

	token_free = (t_token*) token;
	if (!token_free)
		return ;
	if (token_free->text)
		free(token_free->text);
	free(token_free);
}

/**
 * handler_many_char - create a token with many caracteres
 * @stream:	a structure with the list of tokens and other information that will
 * 			be manipulated in the creation of the token.
 * @count:	end of token's string in the line. The subtring token text is:
 * 			stream->index (inclusive) until
 * 			stream->index + count (exclusive)
 * @type:	the token type
 *
 * This function helps to create tokens with many caracteres
 *
 * Return:
 *   On success:
 * 		new token
 * 	 On failure:
 * 		NULL (malloc error!)
*/
t_token	*hdl_many_char(t_stream *stream, t_uint count, t_token_type type)
{
	t_token	*token;
	char	*text;

	text = ft_substr(stream->line + stream->index, 0, count);
	if (!text)
		return (NULL);
	token = create_token(text, type);
	if (!token)
		free(text);
	stream->index += count;
	return (token);
}

/**
 * handler_hdl_one_char - create a token with one caracter
 * @stream:	a structure with the list of tokens and other information that will
 * 			be manipulated in the creation of the token.
 * @count:	advances the value of the stream index (normally this value is one)
 * @type:	the token type
 *
 * This function treats tokens without text
 *
 * Return:
 *   On success:
 * 		new token
 * 	 On failure:
 * 		return NULL (malloc error!) the list doesn't change
*/
t_token	*hdl_one_char(t_stream *stream, t_uint count, t_token_type type)
{
	t_token	*token;

	token = create_token(NULL, type);
	stream->index += count;
	return (token);
}