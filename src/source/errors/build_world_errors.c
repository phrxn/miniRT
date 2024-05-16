/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_world_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:10:55 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/23 14:10:38 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build_world_errors.h"
#include "build_world.h"

static void	show_message_details(int error_code)
{
	if (error_code == ERR_MALLOC_WORLD)
		ft_putstr_fd("malloc the world struct\n", 2);
	if (error_code == ERR_MALLOC_TRANSFOR_MATRIX)
		ft_putstr_fd("malloc the transformation struct\n", 2);
}

void show_error_build_world(int error_code)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("miniRT: build_world: ", 2);
	show_message_details(error_code);
}