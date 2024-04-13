/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:14:41 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/04/13 18:34:11 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"
#include "minirt.h"
#include "messages.h"
#include <stdlib.h>

void	exit_program(t_minirt *ptr, int exit_code, char *message)
{
	if (ptr)
	{
		// dar FREE em GERAL
	}
	if (message)
		show_error_message(message);
	exit(exit_code);
}
