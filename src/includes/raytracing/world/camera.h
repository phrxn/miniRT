/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 01:27:42 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/18 16:20:07 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "matrix.h"

typedef struct	s_camera
{
	int			hsize;
	int			vsize;
	double 		field_of_view;
	t_matrix	*transformation;
	t_matrix	*transformation_inv;
	double		pixel_size;
	double		half_width;
	double		half_height;
	double		half_view;
}	t_camera;

t_matrix	*view_transform(t_matrix *from, t_matrix *to, t_matrix *up);

t_camera	*create_camera(int hsize, int vsize, double field_of_view);

void		destroy_camera(t_camera **camera);

#endif