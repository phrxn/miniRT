#include "shadow_test.h"
#include "shadow.h"
#include "light.h"

#include "assertz.h"
#include <string.h>

#include "dworld.h"
#include "world.h"
#include "matrix.h"
#include "matrix_alloc.h"

void	is_shadowed_test()
{
	create_subtitle("is_shadowed_test");

	t_world *world = dcreate_world(FALSE);
	t_light *light = (t_light *) world->lights->content;


	//test1
	t_matrix *test1Point = matrix_create_point(0, 10, 0);
	assert_svalue(FALSE, is_shadowed(world, light, test1Point), "test1");
	destroy_matrix(&test1Point);

	//test2 
	t_matrix *test2Point = matrix_create_point(10, -10, 10);
	assert_svalue(TRUE, is_shadowed(world, light, test2Point), "test2");
	destroy_matrix(&test2Point);

	//test3
	t_matrix *test3Point = matrix_create_point(-20, 20, -20);
	assert_svalue(FALSE, is_shadowed(world, light, test3Point), "test3");
	destroy_matrix(&test3Point);


	//test4
	t_matrix *test4Point = matrix_create_point(-2, 2, -2);
	assert_svalue(FALSE, is_shadowed(world, light, test4Point), "test4");
	destroy_matrix(&test4Point);

	destroy_world(&world);
}

void	shadow_test(int argc, char **argv)
{
	if (argc != 1 &&  strcmp(argv[1], "shadow_test") != 0)
		return ;
	create_title("shadow_test");
	is_shadowed_test();
}