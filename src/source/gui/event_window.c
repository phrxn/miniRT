/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 22:00:22 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/26 04:24:19 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_window.h"
#include "minirt.h"

#include "mlx.h"
#include "frame.h"
#include <stdlib.h>
#include <stdio.h>

int	window_destroy(void *param)
{
	t_minirt	*minirt;

	minirt = (t_minirt *)param;
	if (!minirt->window.mlx)
		return (0);
	mlx_loop_end(minirt->window.mlx);
	mlx_destroy_image(minirt->window.mlx, minirt->window.image);
	mlx_destroy_window(minirt->window.mlx, minirt->window.window);
	mlx_destroy_display(minirt->window.mlx);
	free(minirt->window.mlx);
	minirt->window.image = NULL;
	minirt->window.window = NULL;
	minirt->window.mlx = NULL;
	return (0);
}

int	window_expose(void *param)
{
	t_minirt	*minirt;

	minirt = (t_minirt *)param;
	draw_frame(minirt);
	return (0);
}
