/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:09:42 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/25 19:53:33 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_params.h"
#include "minirt.h"
#include "window.h"
#include "exit.h"


static void start_minirt_struct(t_minirt *minirt)
{
	minirt->window.mlx = 0;
	minirt->window.window = 0;
	minirt->window.image = 0;
	minirt->window.addr = 0;
	minirt->window.line_length = 0;
	minirt->window.bits_per_pixel = 0;
	minirt->window.endian = 0;
}



#include "file.h"
#include "libft.h"
#include "parser.h"
#include "world.h"
#include "canvas.h"




//teste
#include "matrix_alloc.h"
#include "matrix_utils.h"
#include "matrix_operations.h"
#include <math.h>


/*
static void create_inverted(t_matrix* normal, t_matrix *inverted)
{
	t_matrix	*tmp_inverted_matrix;

	tmp_inverted_matrix = matrix_create_inverse(normal);
	matrix_copy(tmp_inverted_matrix, inverted);
	destroy_matrix(&tmp_inverted_matrix);
}

static t_camera *start_camera()
{
	t_camera *camera = create_camera(WIDTH, HEIGHT, M_PI/2);

	t_matrix *from = matrix_create_point(0, 3, -5);
	t_matrix *to   = matrix_create_point(0, 0, 0);
	t_matrix *up   = matrix_create_vector(0, 1, 0);

	t_matrix *transformation = view_transform(from , to, up);
	matrix_copy(transformation, camera->transformation);
	create_inverted(camera->transformation, camera->transformation_inv);


	destroy_matrix(&from);
	destroy_matrix(&to);
	destroy_matrix(&up);
	destroy_matrix(&transformation);

	return (camera);
}
*/



static void	start_things(t_minirt *minirt, char **argv)
{
	start_minirt_struct(minirt);
	create_window(minirt);
	minirt->canvas = create_canvas(WIDTH, HEIGHT, minirt->window.endian);
	if (!minirt->canvas)
		exit_program(minirt, 1, MERR_MALLOC_CANVAS, 0);
	minirt->fd_rt_file = open_file(argv[1]);
	if (minirt->fd_rt_file == -1)
		exit_program(minirt, 1, MERR_OPEN_RT_FILE, 1);
}

static void make_raytracing(t_minirt *minirt)
{
	t_world	*world;

	world = parser(minirt->fd_rt_file);
	if (!world)
		exit_program(minirt, 1, NULL, 0);
	render(world, minirt->canvas);
	destroy_world(&world);
}

int	main(int argc, char *argv[])
{
	t_minirt	minirt;

	check_params(argc, argv);
	start_things(&minirt, argv);
	make_raytracing(&minirt);
	start_event_handlers(&minirt);

	return (0);

/*
	(void)minirt;


	int fd = open_file(argv[1]);
	if (fd == -1)
		return 1;
	t_world *world = parser(fd);


	//deletar esse funcao
	start_camera();

	t_canvas *canvas = create_canvas(WIDTH, HEIGHT, FALSE);



   #include "create_ppm.h"
	save_ppm(canvas);
*/

}
