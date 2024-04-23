/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:11:58 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/04/22 13:28:32 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "messages.h"
#include "libft.h"
#include <stdio.h>

void	show_error_method(char *method_name, char *message)
{
	ft_putendl_fd("Error", 2);
	if (method_name)
	{
		ft_putstr_fd(method_name, 2);
		ft_putstr_fd(": ", 2);
		if (message)
			ft_putstr_fd(message, 2);
	}
}

void	show_error_message(char *message)
{
	ft_putendl_fd("Error", 2);
	if (message)
		ft_putendl_fd(message, 2);
}

void	show_error_perror(char *message)
{
	ft_putendl_fd("Error", 2);
	if (message)
		perror(message);
}
