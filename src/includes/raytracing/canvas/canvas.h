/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:00:15 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/04/18 21:09:07 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# define WIN_WIDTH 500
# define WIN_HIGHT 500
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
	int		hight;
	int		pixels[WIN_WIDTH * WIN_HIGHT];
	char	is_endian;
}		t_canvas;

void	set_pixel(t_canvas *canvas, int row, int col, t_color *color);

#endif
