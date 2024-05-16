/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:49:58 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/22 23:02:42 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_errors.h"
#include "syntax_errors.h"
#include "libft.h"
#include "token.h"
#include "values_errors.h"

static void	printf_property2(int error_code)
{
	if (error_code == ERR_PROPERTY_VALUES_HEIGHT_INVALID)
		ft_putstr_fd("height (the value must be greather than zero)", 2);
	if (error_code == ERR_PROPERTY_VALUES_COOR_CAMERA)
		ft_putstr_fd("coornenates (all values are 0's)", 2);
}

static void	printf_property(int error_code)
{
	if (error_code == ERR_PROPERTY_VALUES_COOR)
		ft_putstr_fd("coordenates", 2);
	if (error_code == ERR_PROPERTY_VALUES_DIRECTION_CONVERT)
		ft_putstr_fd("direction", 2);
	if (error_code == ERR_PROPERTY_VALUES_DIRECTION_ALL_ZEROS)
		ft_putstr_fd("direction (all values are 0's)", 2);
	if (error_code == ERR_PROPERTY_VALUES_COLOR)
		ft_putstr_fd("color", 2);
	if (error_code == ERR_PROPERTY_VALUES_COLOR_INVALID)
		ft_putstr_fd("color (values must be between 0-255)", 2);
	if (error_code == ERR_PROPERTY_VALUES_FOV)
		ft_putstr_fd("fov", 2);
	if (error_code == ERR_PROPERTY_VALUES_FOV_INVALID)
		ft_putstr_fd("fov (value must be between 0-180)", 2);
	if (error_code == ERR_PROPERTY_VALUES_RADIO)
		ft_putstr_fd("radio", 2);
	if (error_code == ERR_PROPERTY_VALUES_RADIO_INVALID)
		ft_putstr_fd("radio (value must be between 0.0-1.0)", 2);
	if (error_code == ERR_PROPERTY_VALUES_DIAM)
		ft_putstr_fd("diameter", 2);
	if (error_code ==  ERR_PROPERTY_VALUES_DIAM_INVALID)
		ft_putstr_fd("diameter (the value must be greather than zero)", 2);
	if (error_code == ERR_PROPERTY_VALUES_HEIGHT)
		ft_putstr_fd("height", 2);
	return printf_property2(error_code);
}

static void	printf_default_text(int line_number)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("miniRT: parser: line: ", 2);
	ft_putnbr_fd(line_number, 2);
	ft_putstr_fd(" ", 2);
}

void	show_error_grammar_syntax(int error, t_line *line)
{
	t_token	*token_identifier;

	token_identifier = (t_token *)line->token_list->content;
	if (error == OK_SYNTAX)
		return ;
	printf_default_text(line->line_number);
	if (error == ERR_SYNTAX_ELEMENT_NOT_EXIT)
	{
		ft_putstr_fd("the element ", 2);
		ft_putstr_fd(token_identifier->text, 2);
		ft_putendl_fd(" doesn't exit", 2);
		return ;
	}
	ft_putstr_fd("the syntax of element ", 2);
	ft_putstr_fd(token_identifier->text, 2);
	ft_putendl_fd(" is invalid", 2);
}

void	show_error_grammar_value(int error, t_line *line)
{
	t_token	*token_identifier;

	token_identifier = (t_token *)line->token_list->content;
	if (error == OK_SYNTAX)
		return ;
	printf_default_text(line->line_number);
	ft_putstr_fd("the value(s) of property ", 2);
	printf_property(error);
	ft_putstr_fd(" of element ", 2);
	ft_putstr_fd(token_identifier->text, 2);
	ft_putendl_fd(" is(are) invalid", 2);
}