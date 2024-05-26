/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:22:09 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/26 05:03:03 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count_elements.h"
#include "select_element.h"
#include "count_elements_errors.h"
#include "array.h"
#include "libft.h"
#include "line.h"

#include <stdio.h>

static void	count_itens(t_list *valid_line_list, t_count_elements *counter)
{
	t_uint				list_size;
	t_uint				count;
	t_element_type		element_type;
	t_list				*token_list;
	t_line				*line;

	list_size = ft_lstsize(valid_line_list);
	count = 0;
	while (count < list_size)
	{
		line = ft_lstget(valid_line_list, count)->content;
		token_list = line->token_list;
		element_type = get_element_type(token_list);
		if (element_type == ambient)
			counter->ambient_quantity++;
		if (element_type == camera)
			counter->camera_quantity++;
		if (element_type == light)
			counter->light_quantity++;
		count++;
	}
}

static int	is_quantity_valid(t_count_elements *counter)
{
	int	status;

	status = OK_ELEMENT_NUMBERS;
	if (counter->ambient_quantity != 1)
	{
		show_error_count_elements(ERR_NUMBER_OF_AMBIENT);
		status = ERR_ELEMENT_NUMBERS;
	}
	if (counter->camera_quantity != 1)
	{
		show_error_count_elements(ERR_NUMBER_OF_CAMERAS);
		status = ERR_ELEMENT_NUMBERS;
	}
	if (BONUS == FALSE && counter->light_quantity != 1)
	{
		show_error_count_elements(ERR_NUMBER_OF_LIGHT);
		status = ERR_ELEMENT_NUMBERS;
	}
	if (BONUS == TRUE && counter->light_quantity < 1)
	{
		show_error_count_elements(ERR_NUMBER_OF_LIGHT);
		status = ERR_ELEMENT_NUMBERS;
	}
	return (status);
}

/**
 * count_elements - checks if the list has the necessary number of elements to
 * 					create a valid world.
 *
 * @valid_line_list: a valid list line (the list needs to come from the parser)
 *
 * Return:
 * 	On successful:
 * 		OK_ELEMENT_NUMBERS is returned
 * 	On failure:
 * 		ERR_ELEMENT_NUMBERS is returned
*/
int	count_elements(t_list *valid_list_line)
{
	t_count_elements	count_elements;

	count_elements.ambient_quantity = 0;
	count_elements.camera_quantity = 0;
	count_elements.light_quantity = 0;
	count_itens(valid_list_line, &count_elements);
	return (is_quantity_valid(&count_elements));
}
