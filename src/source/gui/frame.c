/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 22:00:28 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/25 18:15:26 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"

void	draw_frame(t_minirt *minirt)
{

	char	*address_image;

	address_image = (char *)minirt->window.addr;

	// percoorer o canvas .... passar o seu array de pixeis para o window.addrs
	// e chamar o

    //mlx_put_image_to_window

	mlx_put_image_to_window(minirt->window.mlx, minirt->window.window, minirt->window.image, 0, 0);
}
