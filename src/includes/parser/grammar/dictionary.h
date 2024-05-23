/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:59:35 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/23 14:57:09 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONARY_H
# define DICTIONARY_H

# include "token.h"
# include "types.h"

//base
char dict_is_a_identifier(t_token *token);
char dict_is_a_pos_int(t_token *token);
char dict_is_a_neg_int(t_token *token);
char dict_is_a_pos_double(t_token *token);
char dict_is_a_neg_double(t_token *token);
char dict_is_a_separator_value(t_token *token);
char dict_is_a_separator_property(t_token *token);
char dict_is_a_eol(t_token *token);

//derivation

char dict_is_a_number(t_token *token);

#endif