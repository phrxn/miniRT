/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:00:15 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/18 15:59:03 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# include "types.h"
# include "color.h"

# define WIN_WIDTH 500
# define WIN_HEIGHT 500

typedef struct s_canvas
{
	int		width;
	int		height;
	int		*pixels;
	int		size;
	char	is_endian;
}		t_canvas;

void		set_pixel(t_canvas *canvas, int row, int col, t_color *color);
int			canvas_start(t_canvas *canvas, int w, int h, char is_endian);
t_canvas	*create_canvas(int w, int h, char is_endian);
void		destroy_canvas(t_canvas **canvas);

#endif
