/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_errors.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:50:17 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/21 22:54:03 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_ERRORS_H
#define PARSER_ERRORS_H

#include "line.h"

void	show_error_grammar_syntax(int error, t_line *line);

void	show_error_grammar_value(int error, t_line *line);

#endif