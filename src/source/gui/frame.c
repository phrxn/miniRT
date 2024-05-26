/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 22:00:28 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/25 19:51:32 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include "types.h"

void	draw_frame(t_minirt *minirt)
{
	int		*address_image;
	t_uint	count_pixels = 0;
	t_uint	canvas_size;

	canvas_size = (WIDTH * HEIGHT);
	address_image = (int *)minirt->window.addr;
	while(count_pixels < canvas_size)
	{
		address_image[count_pixels] = minirt->canvas->pixels[count_pixels];
		count_pixels++;
	}
	mlx_put_image_to_window(minirt->window.mlx, minirt->window.window, minirt->window.image, 0, 0);
}
