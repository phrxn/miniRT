/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:58:06 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/25 19:41:31 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "canvas.h"

# define WIDTH 800
# define HEIGHT 600
# define WIN_TIT "miniRT"

# define MERR_MALLOC_CANVAS "unable to allocate the canvas"
# define MERR_OPEN_RT_FILE "unable to open the rt file"

typedef struct s_window
{
	void	*mlx;
	void	*window;
	void	*image;
	char	*addr;
	int		line_length;
	int		bits_per_pixel;
	int		endian;
}	t_window;

typedef struct s_minirt
{
	t_window	window;
	t_canvas	*canvas;
	int		fd_rt_file;
}	t_minirt;

#endif