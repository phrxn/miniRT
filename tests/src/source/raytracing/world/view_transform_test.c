#include "view_transform_test.h"
#include "view_transform.h"
#include "matrix_alloc.h"

#include "assertz.h"
#include <string.h>

#include "compare.h"

static void view_transform_test1()
{
	create_subtitle("view_transform_test");

	//test 1
	t_matrix *test1From = matrix_create_point(0,0,0);
	t_matrix *test1To   = matrix_create_point(0,0,-1);
	t_matrix *test1Up	= matrix_create_vector(0,1,0);
	t_matrix *test1Expected = matrix_create_identity_4x4();
	t_matrix *test1ViewMatrix = view_transform(test1From, test1To, test1Up);
	assert_svalue(0, compare_matrix(test1Expected, test1ViewMatrix), "test1");

	destroy_matrix(&test1From);
	destroy_matrix(&test1To);
	destroy_matrix(&test1Up);
	destroy_matrix(&test1Expected);
	destroy_matrix(&test1ViewMatrix);

	//test2
	t_matrix *test2From = matrix_create_point(0,0,0);
	t_matrix *test2To   = matrix_create_point(0,0,1);
	t_matrix *test2Up	= matrix_create_vector(0,1,0);
	t_matrix *test2Expected = matrix_create_scaling(-1, 1, -1);
	t_matrix *test2ViewMatrix = view_transform(test2From, test2To, test2Up);
	assert_svalue(0, compare_matrix(test2Expected, test2ViewMatrix), "test2");

	destroy_matrix(&test2From);
	destroy_matrix(&test2To);
	destroy_matrix(&test2Up);
	destroy_matrix(&test2Expected);
	destroy_matrix(&test2ViewMatrix);
}

void	view_transform_test(int argc, char **argv)
{
	if (argc != 1 && strcmp(argv[1], "view_transform_test") != 0)
		return ;
	create_title("view_transform_test");
	view_transform_test1();
}