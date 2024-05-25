/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:14:41 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/25 18:41:33 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"
#include "minirt.h"
#include "messages.h"
#include "minirt_utils.h"
#include <stdlib.h>

void	exit_program(t_minirt *ptr, int exit_code, char *message)
{
	if (ptr)
		terminate(ptr);

	if (message)
		show_error_message(message);
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