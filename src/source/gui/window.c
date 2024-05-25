/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 22:00:34 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/25 18:40:32 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "event_keyboard.h"
#include "event_window.h"
#include "mlx.h"
#include "minirt.h"
#include <stdlib.h>
#include "exit.h"

static void die(t_minirt *minirt, char *str)
{
	(void)minirt;
	(void)str;
	#include <stdio.h>
	printf("saindo no die do window.c\n");
	exit(0);
}

void	start_event_handlers(t_minirt *minirt)
{
	mlx_hook(minirt->window.window, ON_KEYDOWN, (1L << 0), key_pressed, minirt);
	mlx_hook(minirt->window.window, ON_DESTROY, (0), terminate, minirt);
	mlx_hook(minirt->window.window, ON_EXPOSE, (1L << 15), window_expose, minirt);
	mlx_loop(minirt->window.mlx);
}

void	create_window(t_minirt *minirt)  //rename para open_window
{
	t_window	*window;

	window = &minirt->window;
	window->mlx = mlx_init();
	if (!window->mlx)
		exit_program(minirt, 1, MERR_INIT_MLX);
	window->window = mlx_new_window(window->mlx, WIDTH, HEIGHT, WIN_TIT);
	if (!window->window)
	{
		free(window->mlx);
		exit_program(minirt, 1, MERR_MALLOC_MLX);
	}
	window->image = mlx_new_image(window->mlx, WIDTH, HEIGHT);
	if (!window->image)
	{
		free(window->mlx);
		free(window->window);
		die(minirt, MERR_MALLOC_MLX_IMAGE);
	}
	window->addr = mlx_get_data_addr(window->image, &window->bits_per_pixel,
			&window->line_length, &window->endian);
}
