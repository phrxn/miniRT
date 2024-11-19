/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 22:00:09 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/26 03:52:05 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "minirt.h"

# define MERR_INIT_MLX "Mlx_init error."
# define MERR_MALLOC_MLX "Window mlx malloc error."
# define MERR_MALLOC_MLX_IMAGE "Window image malloc error."

enum	e_events
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

void	start_event_handlers(t_minirt *minirt);
void	create_window(t_minirt *minirt);

#endif