/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:00:21 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/25 21:03:08 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

static int	get_position(t_canvas *canvas, int row, int col)
{
	return (row * canvas->width + col);
}

static int	create_pixel(int red, int green, int blue, char endian)
{
	int	pixel;

	pixel = 0;
	if (endian)
	{
		pixel |= (blue << 24);
		pixel |= (green << 16);
		pixel |= (red << 8);
	}
	else
	{
		pixel |= (red << 16);
		pixel |= (green << 8);
		pixel |= (blue);
	}
	return (pixel);
}

static int	color_double_to_pixel(double color)
{
	int	color_tmp;

	color_tmp = COLOR_MAX * color;
	if (color_tmp < 0)
		return (0);
	if (color_tmp > COLOR_MAX)
		return (COLOR_MAX);
	return (color_tmp);
}

static int	color_to_pixel(t_color *color, char endian)
{
	int	red;
	int	green;
	int	blue;
	int	pixel;

	red = color_double_to_pixel(color->red);
	blue = color_double_to_pixel(color->blue);
	green = color_double_to_pixel(color->green);
	pixel = create_pixel(red, green, blue, endian);
	return (pixel);
}

void	set_pixel(t_canvas *canvas, int row, int col, t_color *color)
{
	int	position;

	position = get_position(canvas, row, col);
	canvas->pixels[position] = color_to_pixel(color, canvas->is_endian);
}
