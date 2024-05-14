/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:42:59 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/14 14:28:40 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

void	fill_color(t_color *color, double red, double green, double blue)
{
	color->red = red;
	color->green = green;
	color->blue = blue;
}

void	color_copy(t_color *from, t_color* to)
{
	to->red = from->red;
	to->green = from->green;
	to->blue = from->blue;
}