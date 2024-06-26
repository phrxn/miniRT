/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_element_camera.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:00:19 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/26 05:05:58 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build_element.h"
#include "build_world.h"
#include "world.h"
#include "libft.h"
#include "convert_errors.h"
#include "property_convert.h"
#include "array.h"
#include "minirt.h"
#include "matrix_alloc.h"
#include "matrix_operations.h"
#include "matrix_utils.h"
#include <math.h>

static int	fill_struct(t_element_camera *cam, t_list *token_list)
{
	t_token	*token_tmp;
	int		status;

	status = property_xyz_to_number(ft_lstget(token_list, 2), cam->coor);
	if (status != OK_CONVERT)
		return (status);
	status = property_xyz_to_number(ft_lstget(token_list, 8), cam->direction);
	if (status != OK_CONVERT)
		return (status);
	token_tmp = (t_token *)ft_lstget(token_list, 14)->content;
	status = property_to_int(token_tmp, &cam->fov);
	return (status);
}

static void	set_up(t_matrix *from, t_matrix *to, t_matrix *up)
{
	up->elements[X] = 0;
	up->elements[Y] = 1;
	up->elements[Z] = 0;
	if (from->elements[X] - to->elements[X] == 0
		&& from->elements[Z] - to->elements[Z] == 0
		&& from->elements[Y] - to->elements[Y] < 0)
	{
		up->elements[Y] = 0;
		up->elements[Z] = -1;
		return ;
	}
	if (from->elements[X] - to->elements[X] == 0
		&& from->elements[Z] - to->elements[Z] == 0
		&& from->elements[Y] - to->elements[Y] > 0)
	{
		up->elements[Y] = 0;
		up->elements[Z] = 1;
		return ;
	}
}

static t_matrix	*create_transf(t_element_camera *cam)
{
	t_matrix	*from_p;
	t_matrix	*to_p;
	t_matrix	*up_v;
	t_matrix	*view_transf;
	int			status;

	status = 0;
	from_p = matrix_create_point(cam->coor[X], cam->coor[Y], cam->coor[Z]);
	to_p = matrix_create_point(cam->coor[X] + cam->direction[X], \
		cam->coor[Y] + cam->direction[Y], cam->coor[Z] + cam->direction[Z]);
	up_v = matrix_create_vector(0, 0, 0);
	view_transf = NULL;
	if (!from_p || !to_p || !up_v)
		status = 1;
	set_up(from_p, to_p, up_v);
	if (!status)
		view_transf = view_transform(from_p, to_p, up_v);
	if (!view_transf)
		status = 1;
	destroy_matrix(&from_p);
	destroy_matrix(&to_p);
	destroy_matrix(&up_v);
	if (status)
		destroy_matrix(&view_transf);
	return (view_transf);
}

static int	create_element(t_world *w, t_element_camera *cam_element)
{
	t_camera	*cam;
	t_matrix	*view_transf;
	int			status;
	double		fov;

	fov = cam_element->fov * (M_PI / 180);
	cam = create_camera(WIDTH, HEIGHT, fov);
	view_transf = create_transf(cam_element);
	if (!cam || !view_transf)
	{
		destroy_camera(&cam);
		destroy_matrix(&view_transf);
		return (ERR_BUILD_ELEMENT_MALLOC);
	}
	matrix_copy(view_transf, cam->transformation);
	status = matrix_inverse_4x4(cam->transformation, cam->transformation_inv);
	destroy_matrix(&view_transf);
	if (status != OK_OPERATION)
	{
		destroy_camera(&cam);
		return (ERR_BUILD_ELEMENT_INV_MATRIX);
	}
	w->camera = cam;
	return (OK_BUILD_ELEMENT);
}

int	build_element_camera(t_world *w, t_list *token_list)
{
	t_element_camera	element;
	int					status;

	status = fill_struct(&element, token_list);
	if (status != OK_BUILD_ELEMENT)
		return (ERR_BUILD_CONVERT_TOKENS);
	status = create_element(w, &element);
	return (status);
}
