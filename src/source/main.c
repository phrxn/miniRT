/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:09:42 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/25 02:23:21 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_params.h"
#include "minirt.h"


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

int	main(int argc, char *argv[])
{
	t_minirt	minirt;
	(void) minirt;

	(void)minirt;
	check_params(argc, argv);

	int fd = open_file(argv[1]);
	if (fd == -1)
		return 1;
	t_world *world = parser(fd);


	//deletar esse funcao
	start_camera();

	t_canvas *canvas = create_canvas(WIDTH, HEIGHT, FALSE);

	render(world, canvas);

#include "create_ppm.h"
	save_ppm(canvas);

	return (0);
}
