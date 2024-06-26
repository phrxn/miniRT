/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:11:58 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/25 19:37:56 by dmanoel-         ###   ########.fr       */
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
		ft_putstr_fd("\n", 2);
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
