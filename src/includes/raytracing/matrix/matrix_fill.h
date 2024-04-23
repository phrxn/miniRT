/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_fill.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:56:48 by gacalaza          #+#    #+#             */
/*   Updated: 2024/04/22 22:07:31 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_FILL_H
# define MATRIX_FILL_H

# include "matrix.h"

typedef struct s_shearing 
{
	double	x_to_y;
	double	x_to_z;
	double	y_to_x;
	double	y_to_z;
	double	z_to_x;
	double	z_to_y;

}	t_shearing;


void	matrix_fill_zero(t_matrix *matrix);
void	matrix_fill_translation(t_matrix *matrix, double x, double y, double z);
void	matrix_fill_shearing(t_matrix *matrix, t_shearing *shearing);
void	matrix_fill_rot_x(t_matrix *matrix, double radian);
void	matrix_fill_rot_y(t_matrix *matrix, double radian);
void	matrix_fill_rot_z(t_matrix *matrix, double radian);
void	matrix_fill_scaling(t_matrix *matrix, double x, double y, double z);
void	matrix_fill_identity(t_matrix *matrix);

#endif