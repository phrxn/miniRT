/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chapter5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:03:27 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/04 14:53:43 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_ppm.h"
#include "ray.h"
#include "matrix.h"
#include "matrix_alloc.h"
#include "canvas.h"
#include "shape.h"
#include "matrix_operations.h"
#include "libft.h"
#include "intersect.h"
#include "intersect_utils.h"
#include "hit.h"

int main(void)
{
	t_matrix *ray_origin = matrix_create_point(0,0,-5);

	double wall_z = 10;
	double wall_size = 7;

	t_canvas canvas;
	canvas_start(&canvas, FALSE);

	double pixel_size = wall_size / WIN_WIDTH;

	double half = wall_size / 2;

	double world_y, world_x;

	t_color color; color.red = 1; color.green = 0; color.blue = 0;

	t_shape *shape = create_sphere();

	t_matrix *position = NULL;

	t_ray *r = NULL;
	
	t_list *list;

	for(int y = 0; y < canvas.height -1; y++)
	{
		world_y = half - pixel_size * y;
		for(int x = 0; x < canvas.width -1; x++)
		{
			world_x = -half + pixel_size * x;
			position = matrix_create_point(world_x, world_y, wall_z);

			t_matrix *matrix_nor = matrix_create_subtraction(position, ray_origin);
			matrix_normalization(matrix_nor, matrix_nor);

			r = create_ray(ray_origin, matrix_nor);

			list = intersect_sphere(shape, r);

			if(hit(list))
				set_pixel(&canvas, x, y, &color);
			destroy_matrix(&position);
			destroy_matrix(&matrix_nor);
			destroy_ray(&r);
			ft_lstclear(&list, destroy_intersection2);
		}
	}
	destroy_matrix(&ray_origin);
	destroy_sphere(&shape);
	
	save_ppm(&canvas);
	

	return 0;
}


