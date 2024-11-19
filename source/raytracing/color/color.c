/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:42:59 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/26 04:31:46 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

void	fill_color(t_color *color, double red, double green, double blue)
{
	color->red = red;
	color->green = green;
	color->blue = blue;
}

void	color_copy(t_color *from, t_color *to)
{
	to->red = from->red;
	to->green = from->green;
	to->blue = from->blue;
}
