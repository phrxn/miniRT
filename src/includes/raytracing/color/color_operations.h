/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operations.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 22:05:20 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/04/18 22:19:49 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_OPERATIONS_H
# define COLOR_OPERATIONS_H
# include "canvas.h"

void	color_addition(t_color *a, t_color *b, t_color *result);

void	color_subtration(t_color *a, t_color *b, t_color *result);

void	color_mult_scalar(t_color *a, double scalar, t_color *result);

void	color_mult(t_color *a, t_color *b, t_color *result);

#endif