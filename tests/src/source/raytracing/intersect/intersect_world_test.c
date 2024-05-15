#include "intersect_world_test.h"
#include "intersect_world.h"
#include "matrix_alloc.h"
#include "intersect.h"
#include "intersect_utils.h"

#include "assertz.h"
#include <string.h>

#include "dworld.h"

static void intersect_world_test1()
{
	create_subtitle("intersect_world_test1");


	// test1
	t_world *world = dcreate_world(0);
	t_matrix *test1Center = matrix_create_point(0, 0, -5);
	t_matrix *test1Direct = matrix_create_vector(0, 0, 1);
	t_ray    *test1Ray = create_ray(test1Center, test1Direct);

	t_list *intersects = intersect_world(world, test1Ray);
	assert_svalue(4, ft_lstsize(intersects), "test1 size list == 4");
	assert_double(4, ((t_inter *)intersects->content)->t ,                   "x[0] == 4");
	assert_double(4.5, ((t_inter *)intersects->next->content)->t ,           "x[1] == 4.5");
	assert_double(5.5, ((t_inter *)intersects->next->next->content)->t ,     "x[2] == 5.5");
	assert_double(6, ((t_inter *)intersects->next->next->next->content)->t , "x[3] == 6");

	destroy_world(&world);
	destroy_matrix(&test1Center);
	destroy_matrix(&test1Direct);
	destroy_ray(&test1Ray);
	ft_lstclear(&intersects, destroy_intersection2);


}

void	intersect_world_test(int argc, char **argv)
{
	if (argc != 1 &&  strcmp(argv[1], "intersect_world_test") != 0)
		return ;
	create_title("intersect_world_test");
	intersect_world_test1();

}