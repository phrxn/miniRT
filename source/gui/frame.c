/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 22:00:28 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/26 04:23:27 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "minirt.h"
#include "types.h"

void	draw_frame(t_minirt *minirt)
{
	int		*address_image;
	t_uint	count_pixels;
	t_uint	canvas_size;

	count_pixels = 0;
	canvas_size = (WIDTH * HEIGHT);
	address_image = (int *)minirt->window.addr;
	while (count_pixels < canvas_size)
	{
		address_image[count_pixels] = minirt->canvas->pixels[count_pixels];
		count_pixels++;
	}
	mlx_put_image_to_window(minirt->window.mlx, minirt->window.window,
		minirt->window.image, 0, 0);
}
