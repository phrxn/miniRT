#include "shade_hit_test.h"
#include "shade_hit.h"

#include "dworld.h"
#include "ray.h"
#include "matrix_alloc.h"
#include "prepare_computations.h"

#include "assertz.h"
#include <string.h>

#include "compare.h"

#include "print_object.h"

static void	shade_hit_test1()
{
	create_subtitle("shade_hit_test1");

	//test1
	t_world *test1World = dcreate_world(0);
	t_matrix	*test1Origin = matrix_create_point(0, 0, -5);
	t_matrix	*test1Direct = matrix_create_vector(0, 0, 1);
	t_ray		*test1Ray  = create_ray(test1Origin, test1Direct);
	t_inter		test1Inter; test1Inter.t = 4; test1Inter.shape = (t_shape*)test1World->shapes->content;

	t_prepare_computations *test1Pre = create_pre_computations(&test1Inter, test1Ray);

	t_color test1Return = shade_hit(test1World, test1Pre);
	t_color test1ColorExpected; fill_color(&test1ColorExpected, 0.38066, 0.47583, 0.2855);
	assert_svalue(0, compare_color(&test1ColorExpected, &test1Return), "test1");

	destroy_world(&test1World);
	destroy_matrix(&test1Origin);
	destroy_matrix(&test1Direct);
	destroy_ray(&test1Ray);
	destroy_pre_computations(&test1Pre);

	//test2
	t_world		*test2World = dcreate_world(0);
	ft_lstclear(&test2World->lights, destroy_light2);
	t_color test2light_color;  test2light_color.red = 1;  test2light_color.green = 1;  test2light_color.blue = 1;
	t_light *test2light = create_light(&test2light_color, 0, 0.25, 0);
	t_list *test2ItemLight = ft_lstnew(NULL);
	test2ItemLight->content = test2light;
	test2World->lights = test2ItemLight;
	t_matrix	*test2Origin = matrix_create_point(0, 0, 0);
	t_matrix	*test2Direct = matrix_create_vector(0, 0, 1);
	t_ray		*test2Ray  = create_ray(test2Origin, test2Direct);
	t_inter		test2Inter; test2Inter.t = 0.5; test2Inter.shape = (t_shape*)test2World->shapes->next->content; //sphere 2

	t_prepare_computations *test2pre = create_pre_computations(&test2Inter, test2Ray);

	t_color test2Return = shade_hit(test2World, test2pre);
	t_color test2ColorExpected; fill_color(&test2ColorExpected, 0.90498, 0.90498, 0.90498);
	assert_svalue(0, compare_color(&test2ColorExpected, &test2Return), "test2");

	destroy_world(&test2World);
	destroy_matrix(&test2Origin);
	destroy_matrix(&test2Direct);
	destroy_ray(&test2Ray);
	destroy_pre_computations(&test2pre);
}

void	shade_hit_test(int argc, char **argv)
{
	if (argc != 1 &&  strcmp(argv[1], "shade_hit_test") != 0)
		return ;
	create_title("shade_hit_test");

	shade_hit_test1();
}