/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:45:15 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/07 19:39:34 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
#define COLOR_H

# define COLOR_MAX 255

typedef struct s_color
{
	double	red;
	double	green;
	double	blue;
}		t_color;

void	fill_color(t_color *color, double red, double green, double blue);

#endif