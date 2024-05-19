#include "intersect_plane_test.h"
#include "intersect_plane.h"
#include "intersect.h"
#include "matrix_alloc.h"
#include "libft.h"
#include "array.h"
#include "intersect_utils.h"

#include "shape.h"

#include "assertz.h"
#include <string.h>

void	intersect_plane_test1()
{
	create_subtitle("intersect_plane_test1");

	//test1
	t_shape		*test1Shape     = create_shape(TYPE_PLANE);
	t_matrix	*test1Origin    = matrix_create_point(0, 10, 0);
	t_matrix	*test1Direction = matrix_create_vector(0, 0, 1);
	t_ray		*test1Ray		= create_ray(test1Origin, test1Direction);

	t_list		*test1Inter = intersect(test1Shape, test1Ray);
	assert_address(NULL, test1Inter, "test1");

	destroy_matrix(&test1Origin);
	destroy_matrix(&test1Direction);
	destroy_ray(&test1Ray);
	destroy_shape(&test1Shape);

	//test2
	t_shape		*test2Shape     = create_shape(TYPE_PLANE);
	t_matrix	*test2Origin    = matrix_create_point(0, 1, 0);
	t_matrix	*test2Direction = matrix_create_vector(0, -1, 0);
	t_ray		*test2Ray		= create_ray(test2Origin, test2Direction);

	t_list		*test2Inter = intersect(test2Shape, test2Ray);
	assert_svalue(1, ft_lstsize(test2Inter), "test2");
	assert_svalue(1, ((t_inter *)test2Inter->content)->t, "test2 valor de t");

	destroy_matrix(&test2Origin);
	destroy_matrix(&test2Direction);
	destroy_ray(&test2Ray);
	destroy_shape(&test2Shape);
	ft_lstclear(&test2Inter, destroy_intersection2);

	//test3
	t_shape		*test3Shape     = create_shape(TYPE_PLANE);
	t_matrix	*test3Origin    = matrix_create_point(0, -1, 0);
	t_matrix	*test3Direction = matrix_create_vector(0, 1, 0);
	t_ray		*test3Ray		= create_ray(test3Origin, test3Direction);

	t_list		*test3Inter = intersect(test3Shape, test3Ray);
	assert_svalue(1, ft_lstsize(test3Inter), "test3");
	assert_svalue(1, ((t_inter *)test3Inter->content)->t, "test3 valor de t");

	destroy_matrix(&test3Origin);
	destroy_matrix(&test3Direction);
	destroy_ray(&test3Ray);
	destroy_shape(&test3Shape);
	ft_lstclear(&test3Inter, destroy_intersection2);
}

void	intersect_plane_test(int argc, char **argv)
{
	if (argc != 1 &&  strcmp(argv[1], "intersect_plane_test") != 0)
		return ;
	create_title("intersect_plane_test");

	intersect_plane_test1();
}