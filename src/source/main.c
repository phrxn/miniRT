/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:09:42 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/26 05:11:21 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_params.h"
#include "minirt.h"
#include "minirt_utils.h"
#include "window.h"
#include "exit.h"
#include "parser.h"
#include "world.h"
#include "canvas.h"
#include "file.h"

static void	start_things(t_minirt *minirt, char **argv)
{
	start_minirt(minirt);
	create_window(minirt);
	minirt->canvas = create_canvas(WIDTH, HEIGHT, minirt->window.endian);
	if (!minirt->canvas)
		exit_program(minirt, 1, MERR_MALLOC_CANVAS, 0);
	minirt->fd_rt_file = open_file(argv[1]);
	if (minirt->fd_rt_file == -1)
		exit_program(minirt, 1, MERR_OPEN_RT_FILE, 1);
}

static void	make_raytracing(t_minirt *minirt)
{
	t_world	*world;

	world = parser(minirt->fd_rt_file);
	if (!world)
		exit_program(minirt, 1, NULL, 0);
	render(world, minirt->canvas);
	destroy_world(&world);
}

int	main(int argc, char *argv[])
{
	t_minirt	minirt;

	check_params(argc, argv);
	start_things(&minirt, argv);
	make_raytracing(&minirt);
	start_event_handlers(&minirt);
	return (0);
}
