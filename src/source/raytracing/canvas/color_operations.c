/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 22:05:37 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/04/18 22:14:41 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_operations.h"
#include "canvas.h"

void	color_addition(t_color *a, t_color *b, t_color *result)
{
	result->red = a->red + b->red;
	result->blue = a->blue + b->blue;
	result->green = a->green + b->green;
}

void	color_subtration(t_color *a, t_color *b, t_color *result)
{
	result->red = a->red - b->red;
	result->blue = a->blue - b->blue;
	result->green = a->green - b->green;
}

void	color_mult_scalar(t_color *a, double scalar, t_color *result)
{
	result->red = a->red * scalar;
	result->blue = a->blue * scalar;
	result->green = a->green * scalar;
}

void	color_mult(t_color *a, t_color *b, t_color *result)
{
	result->red = a->red * b->red;
	result->blue = a->blue * b->blue;
	result->green = a->green * b->green;
}
