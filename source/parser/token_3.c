/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:09:15 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/14 14:34:03 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "libft.h"
#include "lexer.h"
#include "peek.h"
#include "types.h"

#include <stdlib.h>

t_token	*token_separator_value(t_stream *stream)
{
	return (hdl_one_char(stream, 1, separator_value));
}

t_token	*token_eol(t_stream *stream)
{
	return (hdl_one_char(stream, 1, eol));
}

t_token	*token_identifier(t_stream *stream)
{
	t_uint	count;

	count = 0;
	while (peek(stream->line[stream->index + count]) != space
		&& peek(stream->line[stream->index + count]) != end_line)
		count++;
	return (hdl_many_char(stream, count, identifier));
}
