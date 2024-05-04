/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:00:21 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/04 15:42:06 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "types.h"

void	canvas_start(t_canvas *canvas, BOOL is_endian)
{
	t_uint	count;

	canvas->width = WIN_WIDTH;
	canvas->height = WIN_HEIGHT;
	canvas->is_endian = is_endian;
	canvas->size = WIN_WIDTH * WIN_HEIGHT;
	count = 0;
	while (count < canvas->size)
	{
		canvas->pixels[count] = 0;
		count++;
	}
}
