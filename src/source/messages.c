/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:11:58 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/04/13 18:27:32 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "messages.h"
#include "libft.h"

void	show_error_message(char *message)
{
	ft_putendl_fd("Error", 2);
	if (message)
	{
		ft_putendl_fd(message, 2);
		return ;
	}
}
