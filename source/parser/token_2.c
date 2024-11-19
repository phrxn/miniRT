/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:09:15 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/14 14:33:44 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "libft.h"
#include "lexer.h"
#include "peek.h"
#include "types.h"

#include <stdlib.h>

static t_token	*token_double(t_stream *stream, t_uint count, t_token_type	typ)
{
	t_uint			count_fra;

	count_fra = count;
	while (peek(stream->line[stream->index + count_fra]) == number)
		count_fra++;
	if (count_fra > count)
		return (hdl_many_char(stream, count_fra, typ));
	return (hdl_many_char(stream, count_fra, identifier));
}

static t_token	*token_number(t_stream *stream, t_token_type type)
{
	t_uint	count_int;
	char	char_act;
	char	char_next;

	count_int = 0;
	char_act = stream->line[stream->index];
	char_next = stream->line[stream->index + 1];
	if ((peek(char_act) == signal_pos || peek(char_act) == signal_neg)
		&& peek(char_next) != number)
		return (token_identifier(stream));
	if (peek(char_act) == signal_pos || peek(char_act) == signal_neg)
		count_int++;
	while (peek(stream->line[stream->index + count_int]) == number)
		count_int++;
	if (peek(stream->line[stream->index + count_int]) == dot)
	{
		count_int++;
		if (type == pos_int)
			return (token_double(stream, count_int, pos_double));
		if (type == neg_int)
			return (token_double(stream, count_int, neg_double));
	}
	return (hdl_many_char(stream, count_int, type));
}

t_token	*token_number_positive(t_stream *stream)
{
	return (token_number(stream, pos_int));
}

t_token	*token_number_negative(t_stream *stream)
{
	return (token_number(stream, neg_int));
}

t_token	*token_separator_property(t_stream *stream)
{
	t_uint	count_sep;

	count_sep = 0;
	while (peek(stream->line[stream->index + count_sep]) == space)
		count_sep++;
	return (hdl_many_char(stream, count_sep, separator_property));
}
