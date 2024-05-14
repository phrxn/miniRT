#include "world_test.h"
#include "world.h"
#include "matrix_alloc.h"
#include "ray.h"

#include "assertz.h"
#include <string.h>

#include "dworld.h"

#include "compare.h"

void 	create_world_test()
{
	create_subtitle("create_world_test");

	t_world *world = dcreate_world();
	destroy_world(&world);
	assert_utils_print_ok("create and destroy");
}

void	colot_at_test()
{
	create_subtitle("colot_at_test");

	//test1
	t_world		*test1World = dcreate_world();
	t_matrix	*test1Origin = matrix_create_point(0,0,-5);
	t_matrix	*test1Direct = matrix_create_vector(0,1,0);
	t_ray		*test1Ray = create_ray(test1Origin, test1Direct);
	t_color		test1ColorReturn = color_at(test1World, test1Ray);
	t_color		test1ColorExpected; fill_color(&test1ColorExpected, 0,0,0);

	assert_svalue(0, compare_color(&test1ColorExpected, &test1ColorReturn), "test1: color: 0,0,0");

	destroy_world(&test1World);
	destroy_matrix(&test1Origin);
	destroy_matrix(&test1Direct);
	destroy_ray(&test1Ray);

	//test2
	t_world		*test2World = dcreate_world();
	t_matrix	*test2Origin = matrix_create_point(0, 0, -5);
	t_matrix	*test2Direct = matrix_create_vector(0, 0, 1);
	t_ray		*test2Ray = create_ray(test2Origin, test2Direct);
	t_color		test2ColorReturn = color_at(test2World, test2Ray);
	t_color		test2ColorExpected; fill_color(&test2ColorExpected, 0.38066, 0.47583, 0.2855);

	assert_svalue(0, compare_color(&test2ColorExpected, &test2ColorReturn), "test2 color: 0.38066, 0.47583, 0.2855");

	destroy_world(&test2World);
	destroy_matrix(&test2Origin);
	destroy_matrix(&test2Direct);
	destroy_ray(&test2Ray);

}

void	world_test(int argc, char **argv)
{
	if (argc != 1 &&  strcmp(argv[1], "world_test") != 0)
		return ;
	create_title("world_test");

	create_world_test();
	colot_at_test();
}