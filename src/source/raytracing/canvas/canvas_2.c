/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:00:21 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/26 04:22:06 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "types.h"
#include "libft.h"

int	canvas_start(t_canvas *canvas, int w, int h, char is_endian)
{
	canvas->width = w;
	canvas->height = h;
	canvas->is_endian = is_endian;
	canvas->size = w * h;
	canvas->pixels = ft_calloc(canvas->size, sizeof(*(canvas->pixels)));
	if (!canvas->pixels)
		return (1);
	return (0);
}

t_canvas	*create_canvas(int w, int h, char is_endian)
{
	t_canvas	*canvas;

	canvas = ft_calloc(1, sizeof(*canvas));
	if (!canvas)
		return (NULL);
	canvas->width = w;
	canvas->height = h;
	canvas->is_endian = is_endian;
	canvas->size = w * h;
	canvas->pixels = ft_calloc(canvas->size, sizeof(*(canvas->pixels)));
	if (!canvas->pixels)
		destroy_canvas(&canvas);
	return (canvas);
}

void	destroy_canvas(t_canvas **canvas)
{
	t_canvas	*canvas_tmp;

	if (!canvas || !*canvas)
		return ;
	canvas_tmp = *canvas;
	if (canvas_tmp->pixels)
		free(canvas_tmp->pixels);
	free(canvas_tmp);
	*canvas = NULL;
}
