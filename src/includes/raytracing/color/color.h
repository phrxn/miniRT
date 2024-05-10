/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:45:15 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/09 19:59:45 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# define COLOR_MAX 255

typedef struct s_color
{
	double	red;
	double	green;
	double	blue;
}		t_color;

void	fill_color(t_color *color, double red, double green, double blue);

void	color_copy(t_color *from, t_color* to);

#endif