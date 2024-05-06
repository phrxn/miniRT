#include "matrix_fill_test.h"
#include "matrix_fill.h"
#include "matrix_operations.h"
#include "matrix_alloc.h"

#include "matrix.h"
#include "string.h"

#include "assertz.h"

#include <math.h>

#include "compare.h"

static void	matrix_fill_translation_test()
{
	create_subtitle("matrix_fill_translation_test");

	//test1: Multiplying by a translation matrix
	t_matrix *test1Mtrans = matrix_create_translate(5, -3, 2);
	t_matrix *test1MPoint = matrix_create_point(-3, 4, 5);
	t_matrix *test1MNewPoint = matrix_create_mult(test1Mtrans, test1MPoint);
	assert_svalue(2, 	 test1MNewPoint->elements[X], "test1MNewPoint->elements[X]");
	assert_svalue(1, 	 test1MNewPoint->elements[Y], "test1MNewPoint->elements[y]");
	assert_svalue(7, 	 test1MNewPoint->elements[Z], "test1MNewPoint->elements[Z]");
	assert_svalue(POINT, test1MNewPoint->elements[W], "test1MNewPoint->elements[W]");

	destroy_matrix(&test1Mtrans);
	destroy_matrix(&test1MPoint);
	destroy_matrix(&test1MNewPoint);
	assert_utils_separator();

	//test2: Multiplying by the inverse of a translation matrix
	t_matrix *test2Mtrans = matrix_create_translate(5, -3, 2);
	t_matrix *test2MInverse = matrix_create_inverse(test2Mtrans);
	t_matrix *test2MPoint   = matrix_create_point(-3, 4, 5);
	t_matrix *test2MNewPoint = matrix_create_mult(test2MInverse, test2MPoint);
	assert_svalue(-8, 	 test2MNewPoint->elements[X], "test2MNewPoint->elements[X]");
	assert_svalue(7, 	 test2MNewPoint->elements[Y], "test2MNewPoint->elements[y]");
	assert_svalue(3, 	 test2MNewPoint->elements[Z], "test2MNewPoint->elements[Z]");
	assert_svalue(POINT, test2MNewPoint->elements[W], "test2MNewPoint->elements[W]");

	destroy_matrix(&test2Mtrans);
	destroy_matrix(&test2MInverse);
	destroy_matrix(&test2MPoint);
	destroy_matrix(&test2MNewPoint);
	assert_utils_separator();

	//test3: Translation does not affect vectors
	t_matrix *test3Mtrans = matrix_create_translate(5, -3, 2);
	t_matrix *test3MVector = matrix_create_vector(-3, 4, 5);
	t_matrix *test3MNewPoint = matrix_create_mult(test3Mtrans, test3MVector);
	assert_svalue(-3, 	  test3MNewPoint->elements[X], "test3MVector->elements[X]");
	assert_svalue(4, 	  test3MNewPoint->elements[Y], "test3MVector->elements[y]");
	assert_svalue(5, 	  test3MNewPoint->elements[Z], "test3MVector->elements[Z]");
	assert_svalue(VECTOR, test3MNewPoint->elements[W], "test3MVector->elements[W]");

	destroy_matrix(&test3Mtrans);
	destroy_matrix(&test3MVector);
	destroy_matrix(&test3MNewPoint);
}

static void	matrix_fill_scaling_test()
{
	create_subtitle("matrix_fill_scaling_test");

	//test1: A scaling matrix applied to a point
	t_matrix *test1MScaling = matrix_create_scaling(2, 3, 4);
	t_matrix *test1MPoint = matrix_create_point(-4, 6, 8);
	t_matrix *test1MNewPoint = matrix_create_mult(test1MScaling, test1MPoint);
	assert_svalue(-8, 	 test1MNewPoint->elements[X], "test1MNewPoint->elements[X]");
	assert_svalue(18, 	 test1MNewPoint->elements[Y], "test1MNewPoint->elements[y]");
	assert_svalue(32, 	 test1MNewPoint->elements[Z], "test1MNewPoint->elements[Z]");
	assert_svalue(POINT, test1MNewPoint->elements[W], "test1MNewPoint->elements[W]");

	destroy_matrix(&test1MScaling);
	destroy_matrix(&test1MPoint);
	destroy_matrix(&test1MNewPoint);
	assert_utils_separator();

	//test2: A scaling matrix applied to a vector
	t_matrix *test2MScaling = matrix_create_scaling(2, 3, 4);
	t_matrix *test2MPoint = matrix_create_vector(-4, 6, 8);
	t_matrix *test2MNewVector = matrix_create_mult(test2MScaling, test2MPoint);
	assert_svalue(-8, 	 test2MNewVector->elements[X], "test2MNewVector->elements[X]");
	assert_svalue(18, 	 test2MNewVector->elements[Y], "test2MNewVector->elements[y]");
	assert_svalue(32, 	 test2MNewVector->elements[Z], "test2MNewVector->elements[Z]");
	assert_svalue(VECTOR, test2MNewVector->elements[W], "test2MNewVector->elements[W]");

	destroy_matrix(&test2MScaling);
	destroy_matrix(&test2MPoint);
	destroy_matrix(&test2MNewVector);
	assert_utils_separator();

	//test3: Multiplying by the inverse of a scaling matrix
	t_matrix *test3MScaling =  matrix_create_scaling(2, 3, 4);
	t_matrix *test3MInverse = matrix_create_inverse(test3MScaling);
	t_matrix *test3MVector   = matrix_create_vector(-4, 6, 8);
	t_matrix *test3MNewPoint = matrix_create_mult(test3MInverse, test3MVector);
	assert_svalue(-2, 	 test3MNewPoint->elements[X], "test3MNewPoint->elements[X]");
	assert_svalue(2, 	 test3MNewPoint->elements[Y], "test3MNewPoint->elements[y]");
	assert_svalue(2, 	 test3MNewPoint->elements[Z], "test3MNewPoint->elements[Z]");
	assert_svalue(VECTOR, test3MNewPoint->elements[W], "test3MNewPoint->elements[W]");

	destroy_matrix(&test3MScaling);
	destroy_matrix(&test3MInverse);
	destroy_matrix(&test3MVector);
	destroy_matrix(&test3MNewPoint);
	assert_utils_separator();

	//test4: Reflection is scaling by a negative value
	t_matrix *test4MScaling = matrix_create_scaling(-1, 1, 1);
	t_matrix *test4MPoint = matrix_create_point(2, 3, 4);
	t_matrix *test4MNewPoint = matrix_create_mult(test4MScaling, test4MPoint);
	assert_svalue(-2, 	 test4MNewPoint->elements[X], "test4MNewPoint->elements[X]");
	assert_svalue(3, 	 test4MNewPoint->elements[Y], "test4MNewPoint->elements[y]");
	assert_svalue(4, 	 test4MNewPoint->elements[Z], "test4MNewPoint->elements[Z]");
	assert_svalue(POINT, test4MNewPoint->elements[W], "test4MNewPoint->elements[W]");

	destroy_matrix(&test4MScaling);
	destroy_matrix(&test4MPoint);
	destroy_matrix(&test4MNewPoint);
}

static void	matrix_fill_rot_x_test()
{
	create_subtitle("matrix_fill_rot_x_test");

	//test1: Rotating a point around the x axis
	t_matrix *test1MPoint = matrix_create_point(0, 1, 0);
	t_matrix *test1MHalfQuarter =  matrix_create_rot_x(M_PI / 4);
	t_matrix *test1MFullQuarter =  matrix_create_rot_x(M_PI / 2);
	double test1Value1 = sqrt(2)/2;

	t_matrix *test1MPoint2 = matrix_create_mult(test1MHalfQuarter, test1MPoint);
	assert_svalue(0, 	 test1MPoint2->elements[X], 							  "test1MPoint2->elements[X]");
	assert_svalue(0, 	 compare_double(test1Value1, test1MPoint2->elements[Y]) , "test1MPoint2->elements[y]");
	assert_svalue(0, 	 compare_double(test1Value1, test1MPoint2->elements[Z]),  "test1MPoint2->elements[Z]");
	assert_svalue(POINT, test1MPoint2->elements[W],                               "test1MPoint2->elements[W]");
	t_matrix *test1MPoint3 = matrix_create_mult(test1MFullQuarter, test1MPoint);
	assert_svalue(0, 	 test1MPoint3->elements[X],                    "test1MPoint3->elements[X]");
	assert_svalue(0, 	 compare_double(0, test1MPoint3->elements[Y]), "test1MPoint3->elements[y]");
	assert_svalue(1, 	 compare_double(0, test1MPoint3->elements[Z]), "test1MPoint3->elements[Z]");
	assert_svalue(POINT, test1MPoint3->elements[W],                    "test1MPoint3->elements[W]");

	destroy_matrix(&test1MPoint);
	destroy_matrix(&test1MHalfQuarter);
	destroy_matrix(&test1MFullQuarter);
	destroy_matrix(&test1MPoint2);
	destroy_matrix(&test1MPoint3);
	assert_utils_separator();

	//test2: The inverse of an x-rotation rotates in the opposite direction
	t_matrix *test2MPoint = matrix_create_point(0, 1, 0);
	t_matrix *test2MHalfQuarter =  matrix_create_rot_x(M_PI / 4);
	t_matrix *test3Minverse     =  matrix_create_inverse(test2MHalfQuarter);
	double test2Value1 = sqrt(2)/2;

	t_matrix *test2MPoint2 = matrix_create_mult(test3Minverse, test2MPoint);
	assert_svalue(0, 	 test2MPoint2->elements[X], 							  "test2MPoint2->elements[X]");
	assert_svalue(0, 	 compare_double(test2Value1, test2MPoint2->elements[Y]) , "test2MPoint2->elements[y]");
	assert_svalue(0, 	 compare_double(-test2Value1, test2MPoint2->elements[Z]),  "test2MPoint2->elements[Z]");
	assert_svalue(POINT, test2MPoint2->elements[W],                               "test2MPoint2->elements[W]");

	destroy_matrix(&test2MPoint);
	destroy_matrix(&test2MHalfQuarter);
	destroy_matrix(&test3Minverse);
	destroy_matrix(&test2MPoint2);


}

static void	matrix_fill_rot_y_test()
{
	create_subtitle("matrix_fill_rot_y_test");

	//test1: Rotating a point around the y axis
	t_matrix *test1MPoint = matrix_create_point(0, 0, 1);
	t_matrix *test1MHalfQuarter =  matrix_create_rot_y(M_PI / 4);
	t_matrix *test1MFullQuarter =  matrix_create_rot_y(M_PI / 2);
	double test1Value1 = sqrt(2)/2;

	t_matrix *test1MPoint2 = matrix_create_mult(test1MHalfQuarter, test1MPoint);
	assert_svalue(0, 	 compare_double(test1Value1, test1MPoint2->elements[X]),  "test1MPoint2->elements[X]");
	assert_svalue(0, 	  test1MPoint2->elements[Y], 							  "test1MPoint2->elements[y]");
	assert_svalue(0, 	 compare_double(test1Value1, test1MPoint2->elements[Z]),  "test1MPoint2->elements[Z]");
	assert_svalue(POINT, test1MPoint2->elements[W],                               "test1MPoint2->elements[W]");
	t_matrix *test1MPoint3 = matrix_create_mult(test1MFullQuarter, test1MPoint);
	assert_svalue(1, 	 test1MPoint3->elements[X], "test1MPoint3->elements[X]");
	assert_svalue(0, 	 test1MPoint3->elements[Y], "test1MPoint3->elements[y]");
	assert_svalue(0, 	 test1MPoint3->elements[Z], "test1MPoint3->elements[Z]");
	assert_svalue(POINT, test1MPoint3->elements[W], "test1MPoint3->elements[W]");

	destroy_matrix(&test1MPoint);
	destroy_matrix(&test1MHalfQuarter);
	destroy_matrix(&test1MFullQuarter);
	destroy_matrix(&test1MPoint2);
	destroy_matrix(&test1MPoint3);
	
}

static void	matrix_fill_rot_z_test()
{
	create_subtitle("matrix_fill_rot_z_test");

	//test1: Rotating a point around the z axis
	t_matrix *test1MPoint = matrix_create_point(0, 1, 0);
	t_matrix *test1MHalfQuarter =  matrix_create_rot_z(M_PI / 4);
	t_matrix *test1MFullQuarter =  matrix_create_rot_z(M_PI / 2);
	double test1Value1 = sqrt(2)/2;

	t_matrix *test1MPoint2 = matrix_create_mult(test1MHalfQuarter, test1MPoint);
	assert_svalue(0, 	 compare_double(-test1Value1, test1MPoint2->elements[X]), "test1MPoint2->elements[X]");
	assert_svalue(0, 	 compare_double( test1Value1, test1MPoint2->elements[Y]), "test1MPoint2->elements[Z]");
	assert_svalue(0, 	                               test1MPoint2->elements[Z], "test1MPoint2->elements[y]");
	assert_svalue(POINT,                               test1MPoint2->elements[W], "test1MPoint2->elements[W]");
	t_matrix *test1MPoint3 = matrix_create_mult(test1MFullQuarter, test1MPoint);
	assert_svalue(-1, 	 test1MPoint3->elements[X], "test1MPoint3->elements[X]");
	assert_svalue(0, 	 test1MPoint3->elements[Y], "test1MPoint3->elements[y]");
	assert_svalue(0, 	 test1MPoint3->elements[Z], "test1MPoint3->elements[Z]");
	assert_svalue(POINT, test1MPoint3->elements[W], "test1MPoint3->elements[W]");

	destroy_matrix(&test1MPoint);
	destroy_matrix(&test1MHalfQuarter);
	destroy_matrix(&test1MFullQuarter);
	destroy_matrix(&test1MPoint2);
	destroy_matrix(&test1MPoint3);
}

static void	matrix_fill_shearing_test()
{
	create_subtitle("matrix_fill_shearing_test");

	//test1: A shearing transformation moves x in proportion to y
	t_shearing test1s; test1s.x_to_y = 1, test1s.x_to_z = 0;
		               test1s.y_to_x = 0, test1s.y_to_z = 0;
					   test1s.z_to_x = 0, test1s.z_to_y = 0;
	t_matrix   *test1Matrix1  = matrix_create_shearing(&test1s);
	t_matrix   *test1Point    = matrix_create_point(2,3,4);
	t_matrix   *test1NewPoint = matrix_create_mult(test1Matrix1, test1Point);
	assert_svalue(5, 	 test1NewPoint->elements[X], "test1NewPoint->elements[X]");
	assert_svalue(3, 	 test1NewPoint->elements[Y], "test1NewPoint->elements[y]");
	assert_svalue(4, 	 test1NewPoint->elements[Z], "test1NewPoint->elements[Z]");
	assert_svalue(POINT, test1NewPoint->elements[W], "test1NewPoint->elements[W]");

	destroy_matrix(&test1Matrix1);
	destroy_matrix(&test1Point);
	destroy_matrix(&test1NewPoint);
	assert_utils_separator();


	//test2: A shearing transformation moves x in proportion to z
	t_shearing test2s; test2s.x_to_y = 0, test2s.x_to_z = 1;
		               test2s.y_to_x = 0, test2s.y_to_z = 0;
					   test2s.z_to_x = 0, test2s.z_to_y = 0;
	t_matrix   *test2Matrix1  = matrix_create_shearing(&test2s);
	t_matrix   *test2Point    = matrix_create_point(2,3,4);
	t_matrix   *test2NewPoint = matrix_create_mult(test2Matrix1, test2Point);
	assert_svalue(6, 	 test2NewPoint->elements[X], "test2NewPoint->elements[X]");
	assert_svalue(3, 	 test2NewPoint->elements[Y], "test2NewPoint->elements[y]");
	assert_svalue(4, 	 test2NewPoint->elements[Z], "test2NewPoint->elements[Z]");
	assert_svalue(POINT, test2NewPoint->elements[W], "test2NewPoint->elements[W]");

	destroy_matrix(&test2Matrix1);
	destroy_matrix(&test2Point);
	destroy_matrix(&test2NewPoint);
	assert_utils_separator();

	//test3: A shearing transformation moves y in proportion to x
	t_shearing test3s; test3s.x_to_y = 0, test3s.x_to_z = 0;
		               test3s.y_to_x = 1, test3s.y_to_z = 0;
					   test3s.z_to_x = 0, test3s.z_to_y = 0;
	t_matrix   *test3Matrix1  = matrix_create_shearing(&test3s);
	t_matrix   *test3Point    = matrix_create_point(2,3,4);
	t_matrix   *test3NewPoint = matrix_create_mult(test3Matrix1, test3Point);
	assert_svalue(2, 	 test3NewPoint->elements[X], "test3NewPoint->elements[X]");
	assert_svalue(5, 	 test3NewPoint->elements[Y], "test3NewPoint->elements[y]");
	assert_svalue(4, 	 test3NewPoint->elements[Z], "test3NewPoint->elements[Z]");
	assert_svalue(POINT, test3NewPoint->elements[W], "test3NewPoint->elements[W]");

	destroy_matrix(&test3Matrix1);
	destroy_matrix(&test3Point);
	destroy_matrix(&test3NewPoint);
	assert_utils_separator();

	//test4: A shearing transformation moves y in proportion to z
	t_shearing test4s; test4s.x_to_y = 0, test4s.x_to_z = 0;
		               test4s.y_to_x = 0, test4s.y_to_z = 1;
					   test4s.z_to_x = 0, test4s.z_to_y = 0;
	t_matrix   *test4Matrix1  = matrix_create_shearing(&test4s);
	t_matrix   *test4Point    = matrix_create_point(2,3,4);
	t_matrix   *test4NewPoint = matrix_create_mult(test4Matrix1, test4Point);
	assert_svalue(2, 	 test4NewPoint->elements[X], "test4NewPoint->elements[X]");
	assert_svalue(7, 	 test4NewPoint->elements[Y], "test4NewPoint->elements[y]");
	assert_svalue(4, 	 test4NewPoint->elements[Z], "test4NewPoint->elements[Z]");
	assert_svalue(POINT, test4NewPoint->elements[W], "test4NewPoint->elements[W]");

	destroy_matrix(&test4Matrix1);
	destroy_matrix(&test4Point);
	destroy_matrix(&test4NewPoint);
	assert_utils_separator();

	//test5: A shearing transformation moves z in proportion to x
	t_shearing test5s; test5s.x_to_y = 0, test5s.x_to_z = 0;
		               test5s.y_to_x = 0, test5s.y_to_z = 0;
					   test5s.z_to_x = 1, test5s.z_to_y = 0;
	t_matrix   *test5Matrix1  = matrix_create_shearing(&test5s);
	t_matrix   *test5Point    = matrix_create_point(2,3,4);
	t_matrix   *test5NewPoint = matrix_create_mult(test5Matrix1, test5Point);
	assert_svalue(2, 	 test5NewPoint->elements[X], "test5NewPoint->elements[X]");
	assert_svalue(3, 	 test5NewPoint->elements[Y], "test5NewPoint->elements[y]");
	assert_svalue(6, 	 test5NewPoint->elements[Z], "test5NewPoint->elements[Z]");
	assert_svalue(POINT, test5NewPoint->elements[W], "test5NewPoint->elements[W]");

	destroy_matrix(&test5Matrix1);
	destroy_matrix(&test5Point);
	destroy_matrix(&test5NewPoint);
	assert_utils_separator();

	//test6: A shearing transformation moves z in proportion to y
	t_shearing test6s; test6s.x_to_y = 0, test6s.x_to_z = 0;
		               test6s.y_to_x = 0, test6s.y_to_z = 0;
					   test6s.z_to_x = 0, test6s.z_to_y = 1;
	t_matrix   *test6Matrix1  = matrix_create_shearing(&test6s);
	t_matrix   *test6Point    = matrix_create_point(2,3,4);
	t_matrix   *test6NewPoint = matrix_create_mult(test6Matrix1, test6Point);
	assert_svalue(2, 	 test6NewPoint->elements[X], "test6NewPoint->elements[X]");
	assert_svalue(3, 	 test6NewPoint->elements[Y], "test6NewPoint->elements[y]");
	assert_svalue(7, 	 test6NewPoint->elements[Z], "test6NewPoint->elements[Z]");
	assert_svalue(POINT, test6NewPoint->elements[W], "test6NewPoint->elements[W]");

	destroy_matrix(&test6Matrix1);
	destroy_matrix(&test6Point);
	destroy_matrix(&test6NewPoint);
	assert_utils_separator();

}

void matrix_fill_test(int argc, char **argv)
{
	if (argc != 1 &&  strcmp(argv[1], "matrix_fill_test") != 0)
		return ;

	create_title("matrix_fill_test");

	matrix_fill_translation_test();
	matrix_fill_scaling_test();
	matrix_fill_rot_x_test();
	matrix_fill_rot_y_test();
	matrix_fill_rot_z_test();
	matrix_fill_shearing_test();
}