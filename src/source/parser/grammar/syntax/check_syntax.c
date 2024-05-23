/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:42:28 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/24 19:55:22 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_syntax.h"
#include "syntax_elements.h"
#include "select_element.h"
#include "syntax_errors.h"
#include "line.h"

/**
 * check_line_syntax - check the syntax of a struct t_line
 * @line:	a pointer to line struct with a non-empty (null) t_list tokens
 *
 * checks the token list syntax, and returns one of the values contained
 * in the syntax_errors file.
 *
 * Return:
 * 	On successful:
 * 		OK_SYNTAX value is returned.
 * 	On Failure:
 * 		Other values other then OK_SYNTAX (see syntax_errors.h header to all
 * 		values)
*/
int	check_line_syntax(t_line *line)
{
	t_list			*token_list;
	t_element_type	element_type;

	token_list = line->token_list;
	element_type = get_element_type(token_list);
	if (element_type == ambient)
		return (syntax_ambient(token_list));
	if (element_type == camera)
		return (syntax_camera(token_list));
	if (element_type == light)
		return (syntax_light(token_list));
	if (element_type == sphere)
		return (syntax_sphere(token_list));
	if (element_type == plane)
		return (syntax_plane(token_list));
	if (element_type == cylinder)
		return (syntax_cylinder(token_list));
	return (ERR_SYNTAX_ELEMENT_NOT_EXIT);
}
