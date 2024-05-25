/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:57:41 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/25 18:35:26 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_utils.h"
#include "minirt.h"
#include "event_window.h"

void	start_minirt(t_minirt *minirt)
{
	minirt->window.mlx = 0;
	minirt->window.window = 0;
	minirt->window.image = 0;
	minirt->window.addr = 0;
	minirt->window.line_length = 0;
	minirt->window.bits_per_pixel = 0;
	minirt->window.endian = 0;
}

void	destroy_minirt(t_minirt *minirt)
{
	window_destroy(minirt);
}