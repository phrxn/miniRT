/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:08:45 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/24 19:56:08 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_values.h"
#include "select_element.h"
#include "values_errors.h"
#include "values_elements.h"
#include "line.h"

/**
 * check_line_values - check the values of a struct t_line
 * @line:	a pointer to line struct with a non-empty (null) t_list tokens
 *
 * checks the values from tokens of the token list of line, and returns one of
 * the values contained in the values_errors file.
 *
 * Return:
 * 	On successful:
 * 		OK_SYNTAX value is returned.
 * 	On Failure:
 * 		Other values other then OK_SYNTAX (see syntax_errors.h header to all
 * 		values)
*/
int	check_line_value(t_line *line)
{
	t_list			*token_list;
	t_element_type	element_type;

	token_list = line->token_list;
	element_type = get_element_type(token_list);
	if (element_type == ambient)
		return (values_ambient(token_list));
	if (element_type == camera)
		return (values_camera(token_list));
	if (element_type == light)
		return (values_light(token_list));
	if (element_type == sphere)
		return (values_sphere(token_list));
	if (element_type == plane)
		return (values_plane(token_list));
	if (element_type == cylinder)
		return (values_cylinder(token_list));
	return (ERR_VALUES_ELEMENT_NOT_EXIT);
}
