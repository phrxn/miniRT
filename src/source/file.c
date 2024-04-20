/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:26:39 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/04/13 21:26:37 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"
#include "messages.h"
#include <fcntl.h>

int	open_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		show_error_perror(MSG_OPEN_RT_FILE);
	return fd;
}
