/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:09:42 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/23 14:47:10 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_params.h"
#include "minirt.h"


#include "file.h"
#include "libft.h"
#include "parser.h"

int	main(int argc, char *argv[])
{
	t_minirt	minirt;
	(void) minirt;

	(void)minirt;
	check_params(argc, argv);

	int fd = open_file(argv[1]);
	if (fd == -1)
		return 1;
	t_world *line_list = parser(fd);
	(void) line_list;


	return (0);
}
