/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:26:39 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/04/22 13:25:29 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"
#include "messages.h"
#include "minirt.h"
#include "exit.h"
#include <fcntl.h>

int	open_file(char *file_name, t_minirt *minirt)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		show_error_perror(MSG_OPEN_RT_FILE);
		terminate(minirt);
	}
	return (fd);
}
