/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:14:41 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/25 19:41:59 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"
#include "minirt.h"
#include "messages.h"
#include "minirt_utils.h"
#include <stdlib.h>

void	exit_program(t_minirt *mini, int exit_code, char *message, int perror)
{
	if (mini)
		destroy_minirt(mini);
	if (message)
	{
		if(perror)
			show_error_perror(message);
		else
			show_error_message(message);
	}
	exit(exit_code);
}

int	terminate(void *minirt)
{
	t_minirt	*minirt_tmp;

	if (!minirt)
		return (1);
	minirt_tmp = (t_minirt *) minirt;
	destroy_minirt(minirt);
	exit(0);
}