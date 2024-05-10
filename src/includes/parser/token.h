/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:34:47 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/06 14:34:47 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "lexer.h"
# include "types.h"

typedef enum	e_token_type
{
	identifier = 1,
	pos_int,
	neg_int,
	pos_double,
	neg_double,
	separator_value,
	separator_property,
	eol
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*text;
}	t_token;

t_token	*create_token(char *text, t_token_type type);

void	destroy_token(t_token **token_free);

void	destroy_token2(void *token);

t_token	*hdl_one_char(t_stream *stream, t_uint count, t_token_type type);

t_token	*hdl_many_char(t_stream *stream, t_uint count, t_token_type type);

t_token	*token_number_positive(t_stream *stream);

t_token	*token_number_negative(t_stream *stream);

t_token	*token_separator_property(t_stream *stream);

t_token	*token_separator_value(t_stream *stream);

t_token	*token_eol(t_stream *stream);

t_token	*token_identifier(t_stream *stream);

#endif