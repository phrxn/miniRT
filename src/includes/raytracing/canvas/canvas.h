/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:00:15 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/01 22:30:21 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# define WIN_WIDTH 500
# define WIN_HEIGHT 500
# define COLOR_MAX 255

typedef struct s_color
{
	double	red;
	double	green;
	double	blue;
}		t_color;

typedef struct s_canvas
{
	int		width;
	int		height;
	int		pixels[WIN_WIDTH * WIN_HEIGHT];
	char	is_endian;
}		t_canvas;

void	set_pixel(t_canvas *canvas, int row, int col, t_color *color);

#endif
