/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_elements_errors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:20:32 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/23 22:31:05 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count_elements_errors.h"
#include "count_elements.h"
#include "libft.h"

void show_error_count_elements(int error_code)
{
	if (error_code == OK_ELEMENT_NUMBERS)
		return ;
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("miniRT: parser: ", 2);
	if (error_code == ERR_NUMBER_OF_CAMERAS)
		ft_putendl_fd("the .rt file must have a camera (only one)", 2);
	if (error_code == ERR_NUMBER_OF_AMBIENT)
		ft_putendl_fd("the .rt file must have a ambient (only one)", 2);
	if (error_code == ERR_NUMBER_OF_LIGHT)
	{
		if (BONUS == FALSE)
			ft_putendl_fd("the .rt file must have a light (only one)", 2);
		else
			ft_putendl_fd("the .rt file must have at least one light.)", 2);
	}
}
