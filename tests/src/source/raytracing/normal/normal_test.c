#include "normal_test.h"
#include "normal_sphere_test.h"
#include "normal.h"
#include "normal_sphere.h"
#include "matrix.h"
#include "matrix_operations.h"
#include "matrix_alloc.h"
#include "shape.h"
#include "compare.h"
#include "matrix_utils.h"

#include "assertz.h"

#include <string.h>
#include <math.h>


static void normal_at_sphere_test()
{

	//test 1
	t_matrix *test1Point1 = matrix_create_point(1,0,0);
	t_shape  *test1Sphere = create_sphere(45);
	t_matrix *test1Normal = normal_at(test1Sphere, test1Point1);
	t_matrix *test1Espected = matrix_create_vector(1,0,0);
	assert_svalue(0, compare_matrix(test1Espected, test1Normal), "normal_at_sphere to 1,0,0");

	destroy_matrix(&test1Point1);
	destroy_sphere(&test1Sphere);
	destroy_matrix(&test1Normal);
	destroy_matrix(&test1Espected);
	assert_utils_separator();

	//test 2
	t_matrix *test2Point1 = matrix_create_point(0,1,0);
	t_shape  *test2Sphere = create_sphere(45);
	t_matrix *test2Normal = normal_at(test2Sphere, test2Point1);
	t_matrix *test2Espected = matrix_create_vector(0,1,0);
	assert_svalue(0, compare_matrix(test2Espected, test2Normal), "normal_at_sphere to 0,1,0");

	destroy_matrix(&test2Point1);
	destroy_sphere(&test2Sphere);
	destroy_matrix(&test2Normal);
	destroy_matrix(&test2Espected);
	assert_utils_separator();

	//test 3
	t_matrix *test3Point1 = matrix_create_point(0,0,1);
	t_shape  *test3Sphere = create_sphere(45);
	t_matrix *test3Normal = normal_at(test3Sphere, test3Point1);
	t_matrix *test3Espected = matrix_create_vector(0,0,1);
	assert_svalue(0, compare_matrix(test3Espected, test3Normal), "normal_at_sphere to 0,0,1");

	destroy_matrix(&test3Point1);
	destroy_sphere(&test3Sphere);
	destroy_matrix(&test3Normal);
	destroy_matrix(&test3Espected);
	assert_utils_separator();

	//test4
	double	test4Value = sqrt(3)/3;
	t_matrix *test4Point1 = matrix_create_point(test4Value,test4Value,test4Value);
	t_shape  *test4Sphere = create_sphere(45);
	t_matrix *test4Normal = normal_at(test4Sphere, test4Point1);
	t_matrix *test4Espected = matrix_create_vector(test4Value,test4Value,test4Value);
	assert_svalue(0, compare_matrix(test4Espected, test4Normal), "normal_at_sphere to (sqrt(3)/3,sqrt(3)/3,sqrt(3)/3)");

	destroy_matrix(&test4Point1);
	destroy_sphere(&test4Sphere);
	destroy_matrix(&test4Normal);
	destroy_matrix(&test4Espected);
	assert_utils_separator();

	//test5
	t_matrix *test5Point1 = matrix_create_point(0, 1.70711, -0.70711);
	t_shape  *test5Sphere = create_sphere(45);
	matrix_fill_translation(test5Sphere->transformation, 0, 1, 0);
	t_matrix *test5Normal = normal_at(test5Sphere, test5Point1);
	t_matrix *test5Espected = matrix_create_vector(0, 0.70711, -0.70711);
	assert_svalue(0, compare_matrix(test5Espected, test5Normal), "normal_at_sphere to 0, 0.70711, -0.70711");
	
	destroy_matrix(&test5Point1);
	destroy_sphere(&test5Sphere);
	destroy_matrix(&test5Normal);
	destroy_matrix(&test5Espected);
	assert_utils_separator();


	//test 6 Computing the normal on a transformed sphere
	double	test6Value = sqrt(2)/2;
	t_matrix *test6Point1 = matrix_create_point(0, test6Value, -test6Value);
	t_shape  *test6Sphere = create_sphere(45);
	t_matrix *test6MatrixScale = matrix_create_scaling(1, 0.5, 1);
	t_matrix *test6MatrixRotZ = matrix_create_rot_z(M_PI / 5);
	t_matrix *test6MatrixTransf = matrix_create_multip(test6MatrixScale, test6MatrixRotZ);
	matrix_copy(test6MatrixTransf, test6Sphere->transformation);
	t_matrix *test6Normal = normal_at(test6Sphere, test6Point1);
	t_matrix *test6Espected = matrix_create_vector(0, 0.97014, -0.24254);
	assert_svalue(0, compare_matrix(test6Espected, test6Normal), "normal_at_sphere to 0, 0.97014, -0.24254");
	
	destroy_matrix(&test6Point1);
	destroy_sphere(&test6Sphere);
	destroy_matrix(&test6MatrixScale);
	destroy_matrix(&test6MatrixRotZ);
	destroy_matrix(&test6MatrixTransf);
	destroy_matrix(&test6Normal);
	destroy_matrix(&test6Espected);
	assert_utils_separator();
}


void	normal_test(int argc, char **argv)
{
	if (argc != 1 &&  strcmp(argv[1], "normal_test") != 0)
		return ;
	create_title("normal_test");

	normal_at_sphere_test();
}