#include "shape_test.h"
#include "shape.h"
#include "matrix.h"
#include "libft.h"
#include "messages.h"
#include "matrix_alloc.h"
#include "types.h"

#include "assertz.h"

#include <string.h>

static void create_sphere_test()
{
	create_subtitle("create_sphere_test");

	t_shape *sphere = create_sphere();
	if (sphere)
	{
		destroy_sphere(&sphere);
		assert_utils_print_ok("create_sphere and destroy_sphere");
	}
	else
		assert_utils_print_error("fatal error malloc");
}

void shape_sphere_test(int argc, char **argv)
{
	if (argc != 1 &&  strcmp(argv[1], "shape_sphere_test") != 0)
		return ;
	create_title("shape_sphere_test");

	create_sphere_test();
}