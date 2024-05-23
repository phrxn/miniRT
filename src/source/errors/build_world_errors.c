/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_world_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:10:55 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/25 00:02:02 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build_world_errors.h"
#include "build_world.h"
#include "line.h"
#include "select_element.h"
#include "array.h"


static void	show_message_details(int error_code)
{
	if (error_code == ERR_BUILD_ELEMENT_NOT_EXIT)
		ft_putstr_fd("the element doesn't exist\n", 2);
	if (error_code == ERR_BUILD_CONVERT_TOKENS)
		ft_putstr_fd("unable to convert file data to a structure\n", 2);
	if (error_code == ERR_BUILD_ELEMENT_MALLOC)
		ft_putstr_fd("it was not possible to malloc some resource to " \
			" create the element\n", 2);
	if (error_code == ERR_BUILD_ELEMENT_INV_MATRIX)
		ft_putstr_fd("element's transformation matrix don't have a inverse"\
			" matrix\n", 2);
	if (error_code == ERR_BUILD_ELEMENT_MAKE_TRANSF_MATRIX)
		ft_putstr_fd("unable to create transformation matrix and"\
			" inverse matrix\n", 2);
}

void show_error_build_world(int error_code)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("miniRT: build_world: ", 2);
	if (error_code == ERR_MALLOC_WORLD)
		ft_putendl_fd(" malloc the world struct", 2);
	if (error_code == ERR_MALLOC_TRANSFOR_MATRIX)
		ft_putendl_fd(" malloc the transformation struct", 2);
}

static void	print_element(t_line *line)
{
	t_element_type	token_type;

	token_type = get_element_type(line->token_list);
	if (token_type == ambient)
		ft_putstr_fd("ambient", 2);
	if (token_type == camera)
		ft_putstr_fd("camera", 2);
	if (token_type == light)
		ft_putstr_fd("light", 2);
	if (token_type == sphere)
		ft_putstr_fd("sphere", 2);
	if (token_type == plane)
		ft_putstr_fd("plane", 2);
	if (token_type == cylinder)
		ft_putstr_fd("cylinder", 2);
}

void show_error_build_element(int error_code, t_line *line)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("miniRT: build_world: element ", 2);
	print_element(line);
	ft_putstr_fd(": ", 2);
	show_message_details(error_code);
	(void)line;
}
