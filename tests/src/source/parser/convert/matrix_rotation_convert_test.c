#include "matrix_rotation_convert_test.h"
#include "matrix_rotation_convert.h"
#include "matrix.h"
#include "matrix_alloc.h"
#include "types.h"
#include "parser.h"
#include "matrix_fill.h"

#include "assertz.h"
#include <string.h>
#include <math.h>

#include "compare.h"

void	tokens_to_rotation_test()
{
	create_subtitle("matrix_rotation_convert1");

	t_transformation tt;
	tt.rotation = matrix_create_identity_4x4();

	//test1.1 (vetor points to up y)
	matrix_fill_identity(tt.rotation);
	double test1_1V3d[3]; test1_1V3d[X] = 0;test1_1V3d[Y] = 1; test1_1V3d[Z] = 0;
	t_matrix *test1_1Expected = matrix_create_identity_4x4();
	tokens_to_rotation(&tt, test1_1V3d);
	assert_svalue(0, compare_matrix(test1_1Expected, tt.rotation), "test1_1 vector to up");
	destroy_matrix(&test1_1Expected);

	//test1.2 (vetor points to up y)
	matrix_fill_identity(tt.rotation);
	double test1_2V3d[3]; test1_2V3d[X] = 0;test1_2V3d[Y] = 0.2; test1_2V3d[Z] = 0;
	t_matrix *test1_2Expected = matrix_create_identity_4x4();
	tokens_to_rotation(&tt, test1_2V3d);
	assert_svalue(0, compare_matrix(test1_2Expected, tt.rotation), "test1_2 vector to up");
	destroy_matrix(&test1_2Expected);

	//test1.3 (vetor points to up y)
	matrix_fill_identity(tt.rotation);
	double test1_3V3d[3]; test1_3V3d[X] = 0;test1_3V3d[Y] = 3; test1_3V3d[Z] = 0;
	t_matrix *test1_3Expected = matrix_create_identity_4x4();
	tokens_to_rotation(&tt, test1_3V3d);
	assert_svalue(0, compare_matrix(test1_3Expected, tt.rotation), "test1_3 vector to up");
	destroy_matrix(&test1_3Expected);
	assert_utils_separator();

	//test2.1 (vetor points to down y)
	matrix_fill_identity(tt.rotation);
	double test2_1V3d[3]; test2_1V3d[X] = 0;test2_1V3d[Y] = -1; test2_1V3d[Z] = 0;
	t_matrix *test2_1Expected = matrix_create_identity_4x4();
	matrix_fill_rot_z(test2_1Expected, -M_PI);
	tokens_to_rotation(&tt, test2_1V3d);
	assert_svalue(0, compare_matrix(test2_1Expected, tt.rotation), "test2_1 vector to down y");
	destroy_matrix(&test2_1Expected);

	//test2.2 (vetor points to down y)
	matrix_fill_identity(tt.rotation);
	double test2_2V3d[3]; test2_2V3d[X] = 0;test2_2V3d[Y] = -0.2; test2_2V3d[Z] = 0;
	t_matrix *test2_2Expected = matrix_create_identity_4x4();
	matrix_fill_rot_z(test2_2Expected, -M_PI);
	tokens_to_rotation(&tt, test2_2V3d);
	assert_svalue(0, compare_matrix(test2_2Expected, tt.rotation), "test2_2 vector to down y");
	destroy_matrix(&test2_2Expected);

	//test2.3 (vetor points to down y)
	matrix_fill_identity(tt.rotation);
	double test2_3V3d[3]; test2_3V3d[X] = 0;test2_3V3d[Y] = -0.2; test2_3V3d[Z] = 0;
	t_matrix *test2_3Expected = matrix_create_identity_4x4();
	matrix_fill_rot_z(test2_3Expected, -M_PI);
	tokens_to_rotation(&tt, test2_3V3d);
	assert_svalue(0, compare_matrix(test2_3Expected, tt.rotation), "test2_3 vector to down y");
	destroy_matrix(&test2_3Expected);
	assert_utils_separator();

	//test3.1 (vetor points to x=1, y=1)
	matrix_fill_identity(tt.rotation);
	double test3_1V3d[3]; test3_1V3d[X] = 1;test3_1V3d[Y] = 1; test3_1V3d[Z] = 0;
	t_matrix *test3_1Expected = matrix_create_identity_4x4();
	set_element(test3_1Expected, 0, 0,  0.70711);
	set_element(test3_1Expected, 0, 1,  0.70711);
	set_element(test3_1Expected, 1, 0, -0.70711);
	set_element(test3_1Expected, 1, 1,  0.70711);
	tokens_to_rotation(&tt, test3_1V3d);
	assert_svalue(0, compare_matrix(test3_1Expected, tt.rotation), "test3_1 vector to x=1, y=1");
	destroy_matrix(&test3_1Expected);

	//test3.2 (vetor points to x=1, y=1, z=1)
	matrix_fill_identity(tt.rotation);
	double test3_2V3d[3]; test3_2V3d[X] = 1;test3_2V3d[Y] = 1; test3_2V3d[Z] = 1;
	t_matrix *test3_2Expected = matrix_create_identity_4x4();
	set_element(test3_2Expected, 0, 0,  0.78868);
	set_element(test3_2Expected, 0, 1,  0.57735);
	set_element(test3_2Expected, 0, 2, -0.21132);
	set_element(test3_2Expected, 1, 0, -0.57735);
	set_element(test3_2Expected, 1, 1,  0.57735);
	set_element(test3_2Expected, 1, 2, -0.57735);
	set_element(test3_2Expected, 2, 0, -0.21132);
	set_element(test3_2Expected, 2, 1,  0.57735);
	set_element(test3_2Expected, 2, 2,  0.78868);
	tokens_to_rotation(&tt, test3_2V3d);
	assert_svalue(0, compare_matrix(test3_2Expected, tt.rotation), "test3_2 vector to x=1, y=1, z=1");
	destroy_matrix(&test3_2Expected);

}

void	matrix_rotation_convert_test(int argc, char **argv)
{
	if (argc != 1 &&  strcmp(argv[1], "matrix_rotation_convert") != 0)
		return ;
	create_title("matrix_rotation_convert");
	tokens_to_rotation_test();
}