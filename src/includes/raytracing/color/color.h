/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:45:15 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/24 13:52:34 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# define COLOR_MAX 255

# define RED 0
# define GREEN 1
# define BLUE 2

typedef struct s_color
{
	double	red;
	double	green;
	double	blue;
}	t_color;

void	fill_color(t_color *color, double red, double green, double blue);

void	color_copy(t_color *from, t_color *to);

static inline double	color_int_to_double(int color)
{
	return ((double)color/ COLOR_MAX);
}

#endif