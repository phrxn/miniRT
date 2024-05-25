/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:09:42 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/25 18:21:22 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_params.h"
#include "minirt.h"
#include "window.h"

static void start_minirt_struct(t_minirt *minirt)
{
	minirt->window.mlx = 0;
	minirt->window.window = 0;
	minirt->window.image = 0;
	minirt->window.addr = 0;
	minirt->window.line_length = 0;
	minirt->window.bits_per_pixel = 0;
	minirt->window.endian = 0;
}


int	main(int argc, char *argv[])
{
	t_minirt	minirt;

	start_minirt_struct(&minirt);
	create_window(&minirt);
	start_event_handlers(&minirt);


	(void)minirt;
	check_params(argc, argv);
	return (0);
}
