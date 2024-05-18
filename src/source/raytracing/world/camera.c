/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 01:28:55 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/18 16:20:43 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "libft.h"
#include "matrix_alloc.h"
#include <math.h>

void		set_aspect(t_camera *new_camera, int hsize, int vsize)
{
	double		aspect;

	aspect = (double) hsize / vsize;
	new_camera->half_width = new_camera->half_view * aspect;
	new_camera->half_height = new_camera->half_view;
	if (aspect >= 1)
	{
		new_camera->half_width = new_camera->half_view;
		new_camera->half_height = new_camera->half_view / aspect;
	}
}

t_camera	*create_camera(int hsize, int vsize, double field_of_view)
{
	t_camera	*new_camera;

	new_camera = ft_calloc(1, sizeof(*new_camera));
	if (!new_camera)
		return (NULL);
	new_camera->hsize = hsize;
	new_camera->vsize = vsize;
	new_camera->field_of_view = field_of_view;
	new_camera->transformation = matrix_create_identity_4x4();
	new_camera->transformation_inv = matrix_create_identity_4x4();
	if (!new_camera->transformation)
	{
		destroy_camera(&new_camera);
		return (NULL);
	}
	new_camera->half_view = tan(field_of_view / 2);
	set_aspect(new_camera, hsize, vsize);
	new_camera->pixel_size = (new_camera->half_width * 2) / hsize;
	return (new_camera);
}

void		destroy_camera(t_camera **camera)
{
	t_camera	*camera_tmp;
	if (!camera || !*camera)
		return ;
	camera_tmp = *camera;
	if (camera_tmp->transformation)
		destroy_matrix(&camera_tmp->transformation);
	if (camera_tmp->transformation_inv)
		destroy_matrix(&camera_tmp->transformation_inv);
	free(camera_tmp);
	*camera = NULL;
}
