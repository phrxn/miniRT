/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 22:55:53 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/22 17:40:40 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "lexer.h"
#include "check_grammar.h"

/**
 * create_a_valid_list_line - create a valid line list
 *
 * @fd:	a valid readable fd.
 *
 * This function create a valid line list to create a world.
 * This list of lines will already be checked (syntax and values)
 *
 * Return:
 * 	On successful;
*/
static t_list	*create_a_valid_list_line(int fd)
{
	t_list	*list_line;
	int		grammar;

	list_line = create_line_list(fd);
	if (!list_line)
		return (NULL);
	grammar = check_list_line_grammar(list_line);
	if (grammar != OK_GRAMMAR)
	{
		destroy_line_list(&list_line);
		return (NULL);
	}
	return (list_line);
}


/**
 * parser - create the world
 *
 * @fd:	a valid readable fd.
 *
 * Return:
 * 	On successful:
 * 		A pointer to world struct
 * 	On failure:
 * 		NULL is returned
*/
t_world *parser(int fd)
{
	t_list	*list_line;

	list_line = create_a_valid_list_line(fd);
	(void) list_line;

	return (NULL);
}
