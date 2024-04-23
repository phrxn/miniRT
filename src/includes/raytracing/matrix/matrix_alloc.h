/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_alloc.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:02:55 by gacalaza          #+#    #+#             */
/*   Updated: 2024/04/22 22:08:43 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_ALLOC_H
# define MATRIX_ALLOC_H

# include "matrix.h"
# include "matrix_fill.h"

t_matrix	*matrix_create_point(double x, double y, double z);
t_matrix	*matrix_create_vector(double x, double y, double z);
t_matrix	*matrix_create_identity_4x4(void);
t_matrix	*matrix_create_inverse(t_matrix *matrix_to_invert);
t_matrix	*matrix_create_multip(t_matrix *a, t_matrix *b);
t_matrix	*matrix_create_translate(double x, double y, double z);
t_matrix	*matrix_create_scaling(double x, double y, double z);
t_matrix	*matrix_create_rot_x(double radians);
t_matrix	*matrix_create_rot_y(double radians);
t_matrix	*matrix_create_rot_z(double radians);
t_matrix	*matrix_create_shearing(t_shearing *shearing);
#endif
