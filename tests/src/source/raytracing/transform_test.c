# include "transform_test.h"
# include "transform.h"

#include "assertz.h"
#include "matrix.h"
#include "matrix_alloc.h"
#include "ray.h"
#include "compare.h"

#include <string.h>

static void transform_test1()
{
    create_subtitle("transform_test1");

	//test1
	t_matrix *test1Point1 = matrix_create_point(1, 2, 3);
	t_matrix *test1Vector1 = matrix_create_vector(0,1,0);
	t_ray    *test1Ray = create_ray(test1Point1, test1Vector1);
	t_matrix *test1MatrixTransla = matrix_create_translate(3,4,5);
	t_ray	 *test1RayTransformed = transform(test1Ray, test1MatrixTransla);

	t_matrix *test1Point2 = matrix_create_point(4, 6, 8);
	t_matrix *test1Vector2 = matrix_create_vector(0, 1, 0);

	assert_svalue(0, compare_matrix(test1Point2, test1RayTransformed->origin)    , "test1: compare origin with origin transformed");
	assert_svalue(0, compare_matrix(test1Vector2, test1RayTransformed->direction), "test1: compare direction with direction transformed");

	destroy_matrix(&test1Point1);
	destroy_matrix(&test1Vector1);
	destroy_ray(&test1Ray);
	destroy_matrix(&test1MatrixTransla);
	destroy_ray(&test1RayTransformed);
	destroy_matrix(&test1Point2);
	destroy_matrix(&test1Vector2);
	assert_utils_separator();

	//test2
	t_matrix *test2Point1 = matrix_create_point(1, 2, 3);
	t_matrix *test2Vector1 = matrix_create_vector(0,1,0);
	t_ray    *test2Ray = create_ray(test2Point1, test2Vector1);
	t_matrix *test2MatrixTransla = matrix_create_scaling(2, 3, 4);
	t_ray	 *test2RayTransformed = transform(test2Ray, test2MatrixTransla);

	t_matrix *test2Point2 = matrix_create_point(2, 6, 12);
	t_matrix *test2Vector2 = matrix_create_vector(0, 3, 0);

	assert_svalue(0, compare_matrix(test2Point2, test2RayTransformed->origin)    , "test2: compare origin with origin transformed");
	assert_svalue(0, compare_matrix(test2Vector2, test2RayTransformed->direction), "test2: compare direction with direction transformed");

	destroy_matrix(&test2Point1);
	destroy_matrix(&test2Vector1);
	destroy_ray(&test2Ray);
	destroy_matrix(&test2MatrixTransla);
	destroy_ray(&test2RayTransformed);
	destroy_matrix(&test2Point2);
	destroy_matrix(&test2Vector2);
}


void transform_test(int argc, char **argv)
{
	if (argc != 1 &&  strcmp(argv[1], "transform_test") != 0)
		return ;
	transform_test1();
}