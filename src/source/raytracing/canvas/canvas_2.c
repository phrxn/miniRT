/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:00:21 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/07 19:33:16 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "types.h"
#include "libft.h"

int	canvas_start(t_canvas *canvas, BOOL is_endian)
{
	canvas->width = WIN_WIDTH;
	canvas->height = WIN_HEIGHT;
	canvas->is_endian = is_endian;
	canvas->size = WIN_WIDTH * WIN_HEIGHT;
	canvas->pixels = ft_calloc(canvas->size, sizeof(*(canvas->pixels)));
	if (canvas->pixels)
		return (1);
	return (0);
}

t_canvas	*create_canvas(BOOL is_endian)
{
	t_canvas	*canvas;

	canvas = ft_calloc(1, sizeof(*canvas));
	if (!canvas)
		return (NULL);
	canvas->width = WIN_WIDTH;
	canvas->height = WIN_HEIGHT;
	canvas->is_endian = is_endian;
	canvas->size = WIN_WIDTH * WIN_HEIGHT;
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