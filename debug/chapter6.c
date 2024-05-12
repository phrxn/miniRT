/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chapter6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:03:27 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/12 02:14:31 by dmanoel-         ###   ########.fr       */
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
#include "color.h"
#include "hit.h"
#include "types.h"
#include "light.h"
#include "lighting.h"
#include "normal.h"

int main(void)
{
	t_matrix *ray_origin = matrix_create_point(0,0,-5);

	double wall_z = 10;
	double wall_size = 7;

	t_canvas *canvas = create_canvas(FALSE);

	double pixel_size = wall_size / WIN_WIDTH;

	double half = wall_size / 2;

	double world_y, world_x;

	t_color color;

	//the sphere
	t_shape *shape = create_shape(TYPE_SPHERE);
	fill_material(&shape->material);
	fill_color(&shape->material.color, 1, 0.2, 1);
	matrix_fill_scaling(shape->transformation, 0.5, 1, 1);

	//light
	t_color	light_color; fill_color(&light_color, 1, 1, 1);
	t_light	*light =     create_light(&light_color, -10, 10, -10);


	t_matrix *positionm = NULL;

	t_ray *r = NULL;

	t_list *list;

	t_lighting_params params;

	for(int y = 0; y < canvas->height -1; y++)
	{
		world_y = half - pixel_size * y;
		for(int x = 0; x < canvas->width -1; x++)
		{
			world_x = -half + pixel_size * x;
			positionm = matrix_create_point(world_x, world_y, wall_z);

			t_matrix *ray_direction_normalized = matrix_create_subtraction(positionm, ray_origin);
			matrix_normalization(ray_direction_normalized, ray_direction_normalized);

			r = create_ray(ray_origin, ray_direction_normalized);

			list = intersect(shape, r);

			if(hit(list))
			{
				t_inter *hit1 = (t_inter*) list->content;

				t_matrix	*inv_ray_direction = matrix_create_vector(
								-(ray_direction_normalized->elements[X]),
								-(ray_direction_normalized->elements[Y]),
								-(ray_direction_normalized->elements[Z]));

				params.material = &shape->material;
				params.light = light;
				params.point = position(r, hit1->t);
				params.normalv = normal_at(hit1->shape, params.point);
				params.eyev = inv_ray_direction;

				color = lighting(&params);

				set_pixel(canvas, x, y, &color);

				destroy_matrix(&inv_ray_direction);
				destroy_matrix(&params.point);
				destroy_matrix(&params.normalv);

			}
			destroy_matrix(&positionm);
			destroy_matrix(&ray_direction_normalized);
			destroy_ray(&r);
			ft_lstclear(&list, destroy_intersection2);
		}
	}
	destroy_matrix(&ray_origin);
	destroy_shape(&shape);
	destroy_light(&light);

	save_ppm(canvas);

	destroy_canvas(&canvas);

	return 0;
}


