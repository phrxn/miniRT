/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_errors.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:50:17 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/26 03:51:11 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_ERRORS_H
# define PARSER_ERRORS_H

# include "line.h"

void	show_error_grammar_syntax(int error, t_line *line);
void	show_error_grammar_value(int error, t_line *line);

#endif