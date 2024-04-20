/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:37:04 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/04/20 16:21:44 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_params.h"
#include "exit.h"
#include "libft.h"
#include <stdlib.h>

#include <stdio.h>

static int	is_extension_valid(char *arg)
{
	char	*extension;

	if (!arg)
		return (0);
	if (ft_strlen(arg) < 4)
		return (0);
	extension = ft_strrchr(arg, '.');
	if (!extension)
		return (0);
	if (ft_strncmp(extension, ".rt", 4))
		return (0);
	return(1);
}

void	check_params(int argc, char *argv[])
{
	if (argc != 2)
		exit_program(NULL, 1, MSG_INV_PARAMS);
	if (!is_extension_valid(argv[1]))
		exit_program(NULL, 1, MSG_INV_EXTENSION);
}
