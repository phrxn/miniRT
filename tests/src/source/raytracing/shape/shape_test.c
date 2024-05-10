/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:41:10 by gacalaza          #+#    #+#             */
/*   Updated: 2024/04/23 22:26:10 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape_test.h"
#include "shape.h"
#include "matrix.h"
#include "libft.h"
#include "messages.h"
#include "matrix_alloc.h"
#include "types.h"

#include "assertz.h"

#include <string.h>

static void create_shape_test()
{
	create_subtitle("create_shape_test");

	t_shape *sphere = create_shape(TYPE_SPHERE);
	if (sphere)
	{
		destroy_shape(&sphere);
		assert_utils_print_ok("create_sphere and destroy_sphere");
	}
	else
		assert_utils_print_error("fatal error malloc");
}


void shape_test(int argc, char **argv)
{
	if (argc != 1 &&  strcmp(argv[1], "shape_test") != 0)
		return ;
	create_title("shape_test");

	create_shape_test();
}