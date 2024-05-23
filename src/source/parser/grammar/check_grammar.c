/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grammar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:24:55 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/22 17:40:40 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_grammar.h"
#include "libft.h"
#include "line.h"
#include "types.h"
#include "array.h"
#include "check_syntax.h"
#include "check_values.h"
#include "syntax_errors.h"
#include "parser_errors.h"

/**
 * check_lines_syntax - checks the syntax of all lines in a list of lines
 * @line:	a pointer to a non-null list of lines
 *
 * checks the syntax of all token lists of all lists, and returns one of
 * the values contained in the syntax_error file.
 *
 * Return:
 * 	On successful:
 * 		OK_SYNTAX value is returned.
 * 	On Failure:
 * 		Other values other then OK_SYNTAX (see syntax_errors.h header to all
 * 		values)
*/
static int	check_lines_syntax(t_list *list_line)
{
	int		count;
	int		list_size;
	t_line	*line_item;
	int		status;

	count = 0;
	list_size = ft_lstsize(list_line);
	status = 0;
	while (count < list_size)
	{
		line_item = (t_line*)ft_lstget(list_line, count)->content;
		status = check_line_syntax(line_item);
		if (status)
			break ;
		count++;
	}
	if (status != OK_SYNTAX)
		show_error_grammar_syntax(status, line_item);
	return (status);
}

/**
 * check_lines_syntax - checks the syntax of all lines in a list of lines
 * @line:	a pointer to a non-null list of lines
 *
 * checks the syntax of all token lists of all lists, and returns one of
 * the values contained in the syntax_error file.
 *
 * Return:
 * 	On successful:
 * 		OK_SYNTAX value is returned.
 * 	On Failure:
 * 		Other values other then OK_SYNTAX (see syntax_errors.h header to all
 * 		values)
*/
static int	check_lines_values(t_list *list_line)
{
	int		count;
	int		list_size;
	t_line	*line_item;
	int		status;

	count = 0;
	list_size = ft_lstsize(list_line);
	status = 0;
	while (count < list_size)
	{
		line_item = (t_line*)ft_lstget(list_line, count)->content;
		status = check_line_value(line_item);
		if (status)
			break ;
		count++;
	}
	if (status != OK_SYNTAX)
		show_error_grammar_value(status, line_item);
	return (status);
}


/**
 * check_lines_syntax - checks the grammar of all lines in a list of lines
 * @line:	a pointer to a non-null list of lines.
 *
 * checks the grammar of a list of lines.
 *
 * Return:
 * 	On successful:
 * 		OK_GRAMMAR value is returned.
 * 	On Failure:
 * 		ERR_GRAMMAR value is returned.
 */
int	check_list_line_grammar(t_list *list_line)
{
	if (check_lines_syntax(list_line) != OK_SYNTAX)
		return (ERR_GRAMAR);
	if (check_lines_values(list_line) != OK_SYNTAX)
		return (ERR_GRAMAR);
	return (OK_GRAMMAR);
}
