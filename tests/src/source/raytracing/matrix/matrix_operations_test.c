#include "matrix_operations_test.h"
#include "matrix_operations.h"
#include "matrix.h"
#include "string.h"

#include <math.h>

//test
#include "assertz.h"

//debug
#include "compare.h"


static void matrix_addition_test()
{
	create_subtitle("matrix_addition_test()");

    //test 1 ERR_ROWS_SIZE
	t_matrix matrix1_a; matrix1_a.rows = 1; matrix1_a.cols = 1;
	t_matrix matrix1_b; matrix1_b.rows = 2; matrix1_b.cols = 1;
	int returnz1 = matrix_addition(&matrix1_a, &matrix1_b, NULL);
	assert_svalue(ERR_ROWS_SIZE, returnz1, "test addition 1x1 2x1 (test ERR_ROWS_SIZE)");

    //test 2 ERR_COLS_SIZE
	t_matrix matrix2_a; matrix2_a.rows = 1; matrix2_a.cols = 1;
	t_matrix matrix2_b; matrix2_b.rows = 1; matrix2_b.cols = 2;
	int returnz2 = matrix_addition(&matrix2_a, &matrix2_b, NULL);
	assert_svalue(ERR_COLS_SIZE, returnz2, "test addition 1x1 1x2 (test ERR_COLS_SIZE)");


	//test 3.1 add 1x1 and 1x1
	double matrix3a_elements[1]; matrix3a_elements[0] = -3;
	t_matrix matrix3a; matrix3a.rows = 1; matrix3a.cols = 1; matrix3a.elements = matrix3a_elements;
	double matrix4a_elements[1]; matrix4a_elements[0] = 8;
	t_matrix matrix4a; matrix4a.rows = 1; matrix4a.cols = 1; matrix4a.elements = matrix4a_elements;
	double matrix5a_elements[1]; matrix5a_elements[0] = -9090;
	t_matrix matrix5a; matrix5a.rows = 1; matrix5a.cols = 1; matrix5a.elements = matrix5a_elements;
	int returnz3 = matrix_addition(&matrix3a, &matrix4a, &matrix5a);
	assert_svalue(OK_OPERATION, returnz3,  "test addition: test 3.1  1x1 1x1 return");
	assert_svalue(5, matrix5a_elements[0], "test addition: matrix5a_elements[0]");

	//test 3.2 add 1x1 and 1x1
	double matrix3b_elements[1]; matrix3b_elements[0] = -3;
	t_matrix matrix3b; matrix3b.rows = 1; matrix3b.cols = 1; matrix3b.elements = matrix3b_elements;
	double matrix4b_elements[1]; matrix4b_elements[0] = 8;
	t_matrix matrix4b; matrix4b.rows = 1; matrix4b.cols = 1; matrix4b.elements = matrix4b_elements;
	double matrix5b_elements[1]; matrix5b_elements[0] = -9090;
	t_matrix matrix5b; matrix5b.rows = 1; matrix5b.cols = 1; matrix5b.elements = matrix5b_elements;
	int returnz4 = matrix_addition(&matrix4b, &matrix3b, &matrix5b);
	assert_svalue(OK_OPERATION, returnz4,  "test addition: test 3.2  1x1 1x1 return");
	assert_svalue(5, matrix5b_elements[0], "test addition: matrix5b_elements[0]");

	//test 4.1 add 1x2 and 1x2
	double matrix41a_elements[2]; matrix41a_elements[0] = 10; matrix41a_elements[1] = 5;
	t_matrix matrix41a; matrix41a.rows = 1; matrix41a.cols = 2; matrix41a.elements = matrix41a_elements;
	double matrix41b_elements[2]; matrix41b_elements[0] = -9; matrix41b_elements[1] = -3;
	t_matrix matrix41b; matrix41b.rows = 1; matrix41b.cols = 2; matrix41b.elements = matrix41b_elements;
	double matrix41c_elements[2]; matrix41c_elements[0] = -9090;  matrix41c_elements[0] = -9999;
	t_matrix matrix41c; matrix41c.rows = 1; matrix41c.cols = 1; matrix41c.elements = matrix41c_elements;

	int returnz5 = matrix_addition(&matrix41a, &matrix41b, &matrix41c);
	assert_svalue(OK_OPERATION, returnz5,     "test addition: test 4.1 1x2 1x2 return");
	assert_svalue(1, matrix41c_elements[0],   "test addition: test 4.1 matrix41c_elements[0]");
	assert_svalue(2, matrix41c_elements[1], "test addition: test 4.1 matrix41c_elements[1]");
}



static void matrix_subtraction_test()
{
	create_subtitle("matrix_subtraction_test()");

    //test 1 ERR_ROWS_SIZE
	t_matrix matrix1_a; matrix1_a.rows = 1; matrix1_a.cols = 1;
	t_matrix matrix1_b; matrix1_b.rows = 2; matrix1_b.cols = 1;
	int returnz1 = matrix_subtraction(&matrix1_a, &matrix1_b, NULL);
	assert_svalue(ERR_ROWS_SIZE, returnz1, "test subtration 1x1 2x1 (test ERR_ROWS_SIZE)");

    //test 2 ERR_COLS_SIZE
	t_matrix matrix2_a; matrix2_a.rows = 1; matrix2_a.cols = 1;
	t_matrix matrix2_b; matrix2_b.rows = 1; matrix2_b.cols = 2;
	int returnz2 = matrix_subtraction(&matrix2_a, &matrix2_b, NULL);
	assert_svalue(ERR_COLS_SIZE, returnz2, "test subtration 1x1 1x2 (test ERR_COLS_SIZE)");


	//test 3.1 add 1x1 and 1x1
	double matrix3a_elements[1]; matrix3a_elements[0] = -3;
	t_matrix matrix3a; matrix3a.rows = 1; matrix3a.cols = 1; matrix3a.elements = matrix3a_elements;
	double matrix4a_elements[1]; matrix4a_elements[0] = 8;
	t_matrix matrix4a; matrix4a.rows = 1; matrix4a.cols = 1; matrix4a.elements = matrix4a_elements;
	double matrix5a_elements[1]; matrix5a_elements[0] = -9090;
	t_matrix matrix5a; matrix5a.rows = 1; matrix5a.cols = 1; matrix5a.elements = matrix5a_elements;
	int returnz3 = matrix_subtraction(&matrix3a, &matrix4a, &matrix5a);
	assert_svalue(OK_OPERATION, returnz3,    "test subtration: test 3.1  1x1 1x1 return");
	assert_svalue(-11, matrix5a_elements[0], "test subtration: matrix5a_elements[0]");

	//test 3.2 add 1x1 and 1x1
	double matrix3b_elements[1]; matrix3b_elements[0] = -3;
	t_matrix matrix3b; matrix3b.rows = 1; matrix3b.cols = 1; matrix3b.elements = matrix3b_elements;
	double matrix4b_elements[1]; matrix4b_elements[0] = 8;
	t_matrix matrix4b; matrix4b.rows = 1; matrix4b.cols = 1; matrix4b.elements = matrix4b_elements;
	double matrix5b_elements[1]; matrix5b_elements[0] = -9090;
	t_matrix matrix5b; matrix5b.rows = 1; matrix5b.cols = 1; matrix5b.elements = matrix5b_elements;
	int returnz4 = matrix_subtraction(&matrix4b, &matrix3b, &matrix5b);
	assert_svalue(OK_OPERATION, returnz4,  "test subtration: test 3.2  1x1 1x1 return");
	assert_svalue(11, matrix5b_elements[0], "test subtration: matrix5b_elements[0]");

	//test 4.1 add 1x2 and 1x2
	double matrix41a_elements[2]; matrix41a_elements[0] = 10; matrix41a_elements[1] = 5;
	t_matrix matrix41a; matrix41a.rows = 1; matrix41a.cols = 2; matrix41a.elements = matrix41a_elements;
	double matrix41b_elements[2]; matrix41b_elements[0] = -9; matrix41b_elements[1] = -3;
	t_matrix matrix41b; matrix41b.rows = 1; matrix41b.cols = 2; matrix41b.elements = matrix41b_elements;
	double matrix41c_elements[2]; matrix41c_elements[0] = -9090;  matrix41c_elements[0] = -9999;
	t_matrix matrix41c; matrix41c.rows = 1; matrix41c.cols = 1; matrix41c.elements = matrix41c_elements;

	int returnz5 = matrix_subtraction(&matrix41a, &matrix41b, &matrix41c);
	assert_svalue(OK_OPERATION, returnz5,     "test subtration: test 4.1 1x2 1x2 return");
	assert_svalue(19, matrix41c_elements[0],   "test subtration: test 4.1 matrix41c_elements[0]");
	assert_svalue(8, matrix41c_elements[1],   "test subtration: test 4.1 matrix41c_elements[1]");
}


static void matrix_negation_test()
{
	create_subtitle("matrix_negation_test()");
	//test 1
	double matrix1_elements[3]; matrix1_elements[0] = 0; matrix1_elements[1]= -1; matrix1_elements[2] = 3;
	t_matrix matrix1; matrix1.rows = 1; matrix1.cols = 3; matrix1.elements = matrix1_elements;

	matrix_negation(&matrix1);
	assert_svalue(0, matrix1_elements[0],   "matrix1_elements[0]");
	assert_svalue(1, matrix1_elements[1],   "matrix1_elements[1]");
	assert_svalue(-3, matrix1_elements[2],   "matrix1_elements[2]");
}

static void matrix_mult_scalar_test()
{
	create_subtitle(" matrix_mult_scalar_test");

	//test 1
	double matrix1_elements[3]; matrix1_elements[0] = 0; matrix1_elements[1]= -2; matrix1_elements[2] = 8;
	t_matrix matrix1; matrix1.rows = 1; matrix1.cols = 3; matrix1.elements = matrix1_elements;

	matrix_mult_scalar(&matrix1, 2);
	assert_svalue(0, matrix1_elements[0],   "matrix1_elements[0]");
	assert_svalue(-4, matrix1_elements[1],   "matrix1_elements[1]");
	assert_svalue(16, matrix1_elements[2],   "matrix1_elements[2]");
}

static void matrix_div_scalar_test()
{
	create_subtitle("matrix_div_scalar_test");

	//test 1
	double matrix1_elements[3]; matrix1_elements[0] = 0; matrix1_elements[1]= -2; matrix1_elements[2] = 8;
	t_matrix matrix1; matrix1.rows = 1; matrix1.cols = 3; matrix1.elements = matrix1_elements;

	matrix_div_scalar(&matrix1, 2);
	assert_svalue(0, matrix1_elements[0],   "matrix1_elements[0]");
	assert_svalue(-1, matrix1_elements[1],  "matrix1_elements[1]");
	assert_svalue(4, matrix1_elements[2],   "matrix1_elements[2]");
}

static void matrix_get_magnitude_test()
{
	create_subtitle("matrix_get_magnitude_test");

	//test1 vetor (1, 0, 0)
	double matrix1_elements[4];
		matrix1_elements[X] = 1; matrix1_elements[Y] = 0;
		matrix1_elements[Z] = 0; matrix1_elements[W] = 0;
	t_matrix matrix1; matrix1.rows = 4; matrix1.cols = 1; matrix1.elements = matrix1_elements;
	double return1 = matrix_get_magnitude(&matrix1);
	assert_double(1, return1, "magnitude (1,0,0)");

    //test1 vetor (0, 1, 0)
	double matrix2_elements[4];
		matrix2_elements[X] = 0; matrix2_elements[Y] = 1;
		matrix2_elements[Z] = 0; matrix2_elements[W] = 0;
	t_matrix matrix2; matrix2.rows = 4; matrix2.cols = 1;  matrix2.elements = matrix2_elements;
	double return2 = matrix_get_magnitude(&matrix2);
	assert_double(1, return2, "magnitude (0,1,0)");


    //test1 vetor (0, 0, 1)
	double matrix3_elements[4];
		matrix3_elements[X] = 0; matrix3_elements[Y] = 0;
		matrix3_elements[Z] = 1; matrix3_elements[W] = 0;
	t_matrix matrix3; matrix3.rows = 4; matrix3.cols = 1;  matrix3.elements = matrix3_elements;
	double return3 = matrix_get_magnitude(&matrix3);
	assert_double(1, return3, "magnitude (0,0,1)");

    //test1 vetor (1, 2, 3)
	double matrix4_elements[4];
		matrix4_elements[X] = 1; matrix4_elements[Y] = 2;
		matrix4_elements[Z] = 3; matrix4_elements[W] = 0;
	t_matrix matrix4; matrix4.rows = 4; matrix4.cols = 1;  matrix4.elements = matrix4_elements;
	double returnmatrix4 = matrix_get_magnitude(&matrix4);
	assert_double(sqrt(14), returnmatrix4, "magnitude (1,2,3)");

	//test1 vetor (-1, -2, -3)
	double matrix5_elements[4];
		matrix5_elements[X] = -1; matrix5_elements[Y] = -2;
		matrix5_elements[Z] = -3; matrix5_elements[W] = 0;
	t_matrix matrix5; matrix5.rows = 4; matrix5.cols = 1;  matrix5.elements = matrix5_elements;
	double returnmatrix5 = matrix_get_magnitude(&matrix5);
	assert_double(sqrt(14), returnmatrix5, "magnitude (-1,-2,-3)");

}

static void matrix_normalization_test()
{
	create_subtitle("matrix_normalization_test");

	//test1 ERROR NOT_VECTOR invalid row size
	t_matrix matrix1; matrix1.rows = 3; matrix1.cols = 1;
	double returnmatrix1 = matrix_normalization(&matrix1, NULL);
	assert_svalue(ERR_NOT_VECTOR, returnmatrix1, "invalid vector 1");

	//test2 ERROR NOT_VECTOR invalid col size
	t_matrix matrix2; matrix2.rows = 4; matrix2.cols = 2;
	double returnmatrix2 = matrix_normalization(&matrix2, NULL);
	assert_svalue(ERR_NOT_VECTOR, returnmatrix2, "invalid vector 2");

	//test3 ERROR NOT_VECTOR invalid W value
	t_matrix matrix3; matrix3.rows = 4; matrix3.cols = 2;
	double returnmatrix3 = matrix_normalization(&matrix3, NULL);
	assert_svalue(ERR_NOT_VECTOR, returnmatrix3, "invalid vector 3");

	//test4
	double matrix4a_elements[4];
	t_matrix matrix4a; matrix4a.rows = 4; matrix4a.cols = 1; matrix4a.elements = matrix4a_elements;
	double matrix4b_elements[4];
		matrix4b_elements[X] = 4; matrix4b_elements[Y] = 0;
		matrix4b_elements[Z] = 0; matrix4b_elements[W] = 0;
	t_matrix matrix4b; matrix4b.rows = 4; matrix4b.cols = 1; matrix4b.elements = matrix4b_elements;
	double returntest4 = matrix_normalization(&matrix4b, &matrix4a);
	assert_svalue(OK_OPERATION, returntest4, "normalize (4, 0, 0)");
	assert_svalue(1, matrix4a_elements[X], "matrix4a_elements[X]");
	assert_svalue(0, matrix4a_elements[Y], "matrix4a_elements[Y]");
	assert_svalue(0, matrix4a_elements[Z], "matrix4a_elements[Z]");
	assert_svalue(0, matrix4a_elements[W], "matrix4a_elements[W]");

	//test5
	double matrix5a_elements[4];
	t_matrix matrix5a; matrix5a.rows = 4; matrix5a.cols = 1; matrix5a.elements = matrix5a_elements;
	double matrix5b_elements[4];
		matrix5b_elements[X] = 1; matrix5b_elements[Y] = 2;
		matrix5b_elements[Z] = 3; matrix5b_elements[W] = 0;
	t_matrix matrix5b; matrix5b.rows = 4; matrix5b.cols = 1; matrix5b.elements = matrix5b_elements;
	double returntest5 = matrix_normalization(&matrix5b, &matrix5a);
	assert_svalue(OK_OPERATION, returntest5, "normalize (1,2,3)");
	assert_svalue(0, compare_double(0.26726,matrix5a_elements[X]), "matrix5a_elements[X]");
	assert_svalue(0, compare_double(0.53452,matrix5a_elements[Y]), "matrix5a_elements[Y]");
	assert_svalue(0, compare_double(0.80178,matrix5a_elements[Z]), "matrix5a_elements[Z]");
	assert_svalue(0, matrix5a_elements[W],                         "matrix4a_elements[W]");
}

static void matrix_dot_test()
{
	create_subtitle("matrix_dot_test");

	//test 1 ERR_NOT_VECTOR
	double a1_elements[4]; a1_elements[W] = 1;
	t_matrix a1; a1.elements = a1_elements; a1.rows = 4; a1.cols = 1;
	double a2_elements[4]; a2_elements[W] = 0;
	t_matrix a2; a2.elements = a2_elements; a2.rows = 4; a2.cols = 1;
	int return_1;
	double a1_dot_value;
	return_1 = matrix_dot(&a1, &a2, &a1_dot_value);
	assert_svalue(ERR_NOT_VECTOR, return_1, "not vector 1");
 	a1_elements[W] = 0; a2_elements[W] = 1;
	return_1 = matrix_dot(&a1, &a2, &a1_dot_value);
	assert_svalue(ERR_NOT_VECTOR, return_1, "not vector 2");

	//test 2
	double test2matrix1Elements[4];
		test2matrix1Elements[X] = 1; test2matrix1Elements[Y] = 2; test2matrix1Elements[Z] = 3; test2matrix1Elements[W] = 0;
	t_matrix test2Matrix1; test2Matrix1.rows = 4; test2Matrix1.cols = 1; test2Matrix1.elements = test2matrix1Elements;
	double test2matrix2Elements[4];
		test2matrix2Elements[X] = 2; test2matrix2Elements[Y] = 3; test2matrix2Elements[Z] = 4; test2matrix2Elements[W] = 0;
	t_matrix test2matrix2; test2matrix2.rows = 4; test2matrix2.cols = 1; test2matrix2.elements = test2matrix2Elements;
	int test2Return;
	double test2DotValuel;
	test2Return = matrix_dot(&test2Matrix1, &test2matrix2, &test2DotValuel);
	assert_svalue(OK_OPERATION, test2Return, "test2Return");
	assert_double(20, test2DotValuel, "test2DotValuel");
}

static void matrix_cross_test()
{
	create_subtitle("matrix_cross_test");

	//test 1 ERR_NOT_VECTOR
	double a1_elements[4]; a1_elements[W] = 1;
	t_matrix a1; a1.rows = 4; a1.cols = 1; a1.elements = a1_elements;
	double a2_elements[4]; a2_elements[W] = 0;
	t_matrix a2; a2.rows = 4; a2.cols = 1; a2.elements = a2_elements;
	int return_1;
	return_1 = matrix_cross(&a1, &a2, NULL);
	assert_svalue(ERR_NOT_VECTOR, return_1, "not vector 1");
 	a1_elements[W] = 0; a2_elements[W] = 1;
	return_1 = matrix_cross(&a1, &a2, NULL);
	assert_svalue(ERR_NOT_VECTOR, return_1, "not vector 2");

	//test 2 cross dot
	double test2Matrix1Elements[4];
		test2Matrix1Elements[X] = 1; test2Matrix1Elements[Y] = 2; test2Matrix1Elements[Z] = 3; test2Matrix1Elements[W] = 0;
	t_matrix test2Matrix1; test2Matrix1.rows = 4; test2Matrix1.cols = 1; test2Matrix1.elements = test2Matrix1Elements;
	double test2matrix2Elements[4];
		test2matrix2Elements[X] = 2; test2matrix2Elements[Y] = 3; test2matrix2Elements[Z] = 4; test2matrix2Elements[W] = 0;
	t_matrix test2matrix2; test2matrix2.rows = 4; test2matrix2.cols = 1; test2matrix2.elements = test2matrix2Elements;
	double test2Matrix3Elements[4];
	t_matrix test2Matrix3; test2Matrix3.elements = test2Matrix3Elements;
	int test2Return;
	test2Return = matrix_cross(&test2Matrix1, &test2matrix2, &test2Matrix3);
	assert_svalue(OK_OPERATION, test2Return, "test2Return a * b");
	assert_double(-1, test2Matrix3Elements[X], "test2Matrix3Elements[X]");
	assert_double(2, test2Matrix3Elements[Y], "test2Matrix3Elements[Y]");
	assert_double(-1, test2Matrix3Elements[Z], "test2Matrix3Elements[Z]");
	assert_double(0, test2Matrix3Elements[W], "test2Matrix3Elements[W]");

	test2Return = matrix_cross(&test2matrix2, &test2Matrix1, &test2Matrix3);
	assert_svalue(OK_OPERATION, test2Return, "test2Return b * a");
	assert_double(1, test2Matrix3Elements[X], "test2Matrix3Elements[X]");
	assert_double(-2, test2Matrix3Elements[Y], "test2Matrix3Elements[Y]");
	assert_double(1, test2Matrix3Elements[Z], "test2Matrix3Elements[Z]");
	assert_double(0, test2Matrix3Elements[W], "test2Matrix3Elements[W]");
}

static void matrix_mult_test()
{
	create_subtitle("matrix_mult_test");

	//test1 invalid matrix multiplications operations;
	//test 1A
	t_matrix test1aMatrix1; test1aMatrix1.rows = 3; test1aMatrix1.cols = 2;
	t_matrix test1aMatrix2; test1aMatrix2.rows = 3; test1aMatrix2.cols = 2;
	t_matrix test1aMatrix3; test1aMatrix3.rows = 3; test1aMatrix3.cols = 2;
	int test1aReturn = matrix_mult(&test1aMatrix1, &test1aMatrix2, &test1aMatrix3);
	assert_svalue(ERR_MATRIX_MUL_ROW_COL, test1aReturn, "test1a Return");

	//test 1B
	t_matrix test1bMatrix1; test1bMatrix1.rows = 2; test1bMatrix1.cols = 3;
	t_matrix test1bMatrix2; test1bMatrix2.rows = 3; test1bMatrix2.cols = 3;
	t_matrix test1bMatrix3; test1bMatrix3.rows = 3; test1bMatrix3.cols = 2;
	int test1bReturn  = matrix_mult(&test1bMatrix1, &test1bMatrix2, &test1bMatrix3);
	assert_svalue(ERR_MATRIX_MUL_INV_RESULT, test1bReturn, "test1b Return");

	//test 1C
	t_matrix test1cMatrix1; test1cMatrix1.rows = 2; test1cMatrix1.cols = 3;
	t_matrix test1cMatrix2; test1cMatrix2.rows = 3; test1cMatrix2.cols = 3;
	t_matrix test1cMatrix3; test1cMatrix3.rows = 2; test1cMatrix3.cols = 4;
	int test1cReturn  = matrix_mult(&test1cMatrix1, &test1cMatrix2, &test1cMatrix3);
	assert_svalue(ERR_MATRIX_MUL_INV_RESULT, test1cReturn, "test1c Return");

	//test2 matrix 1x1
	double   test2Matrix1Elements[1] = {2};
	t_matrix test2Matrix1; test2Matrix1.rows = 1; test2Matrix1.cols = 1; test2Matrix1.elements = test2Matrix1Elements;
	double   test2Matrix2Elements[1] = {2};
	t_matrix test2Matrix2; test2Matrix2.rows = 1; test2Matrix2.cols = 1; test2Matrix2.elements = test2Matrix2Elements;
	double   test2Matrix3Elements[1];
	t_matrix test2Matrix3; test2Matrix3.rows = 1; test2Matrix3.cols = 1; test2Matrix3.elements = test2Matrix3Elements;
	int test2Return = matrix_mult(&test2Matrix1, &test2Matrix2, &test2Matrix3);
	assert_svalue(OK_OPERATION , test2Return, "multi 1x1 return ");
	assert_double(4, test2Matrix3Elements[0], "multi 1x1 test2Matrix3Elements[1]");

	//test3 matrix 1x2 x 2x1
	double   test3Matrix1Elements[2] = {2, 3};
	t_matrix test3Matrix1; test3Matrix1.rows = 1; test3Matrix1.cols = 2; test3Matrix1.elements = test3Matrix1Elements;
	double   test3Matrix2Elements[2] = {4, 5};
	t_matrix test3Matrix2; test3Matrix2.rows = 2; test3Matrix2.cols = 1; test3Matrix2.elements = test3Matrix2Elements;
	double   test3Matrix3Elements[2];
	t_matrix test3Matrix3; test3Matrix3.rows = 1; test3Matrix3.cols = 1; test3Matrix3.elements = test3Matrix3Elements;
	int test3Return = matrix_mult(&test3Matrix1, &test3Matrix2, &test3Matrix3);
	assert_svalue(OK_OPERATION , test3Return,  "multi 1x2 * 2x1  return ");
	assert_double(23, test3Matrix3Elements[0], "multi 1x2 * 2x1 test3Matrix3Elements[0]");

	//test4  matrix 2x1x 1x2
	double   test4Matrix1Elements[2] = {2, 3};
	t_matrix test4Matrix1; test4Matrix1.rows = 2; test4Matrix1.cols = 1; test4Matrix1.elements = test4Matrix1Elements;
	double   test4Matrix2Elements[2] = {4, 5};
	t_matrix test4Matrix2; test4Matrix2.rows = 1; test4Matrix2.cols = 2; test4Matrix2.elements = test4Matrix2Elements;
	double   test4Matrix3Elements[4] = {-1000, -1000, -1000, -1000};
	t_matrix test4Matrix3; test4Matrix3.rows = 2; test4Matrix3.cols = 2; test4Matrix3.elements = test4Matrix3Elements;
	double   test4Matrix4Elments[4] = {8, 10, 12, 15};
	t_matrix test4Matrix4; test4Matrix4.rows = 2; test4Matrix4.cols = 2; test4Matrix4.elements = test4Matrix4Elments;
	int test4Return = matrix_mult(&test4Matrix1, &test4Matrix2, &test4Matrix3);
	assert_svalue(OK_OPERATION , test4Return,  "multi 2x1 * 1x2  return ");
	assert_double(0, compare_matrix(&test4Matrix4, &test4Matrix3), "multi 2x1 * 1x2");

    //test5 matrix 3x2 2x2
	double   test5Matrix1Elements[6] = {2, 3, 7, 11, 15, 17};
	t_matrix test5cMatrix1; test5cMatrix1.rows = 3; test5cMatrix1.cols = 2; test5cMatrix1.elements = test5Matrix1Elements;
	double   test5Matrix2Elements[4] = {23, 5, 77, 81};
	t_matrix test5cMatrix2; test5cMatrix2.rows = 2; test5cMatrix2.cols = 2; test5cMatrix2.elements = test5Matrix2Elements;
	double   test5Matrix3Elements[6];
	t_matrix test5Matrix3; test5Matrix3.rows = 3; test5Matrix3.cols = 2; test5Matrix3.elements = test5Matrix3Elements;
	double   test5Matrix4Elements[6] = {277, 253, 1008, 926, 1654, 1452};
	t_matrix test5Matrix4; test5Matrix4.rows = 3; test5Matrix4.cols = 2; test5Matrix4.elements = test5Matrix4Elements;
	int test5Return = matrix_mult(&test5cMatrix1, &test5cMatrix2, &test5Matrix3);
	assert_svalue(OK_OPERATION , test5Return,                      "multi 3x2 * 2x2  return ");
	assert_double(0, compare_matrix(&test5Matrix4, &test5Matrix3), "multi 3x2 * 2x2");

	//test7
	double   test6Matrix1Elements[4] = {23, 5, 77, 81};
	t_matrix test6cMatrix1; test6cMatrix1.rows = 2; test6cMatrix1.cols = 2; test6cMatrix1.elements = test6Matrix1Elements;
	double   test6Matrix2Elements[6] = {2, 3, 7, 11, 15, 17};
	t_matrix test6cMatrix2; test6cMatrix2.rows = 2; test6cMatrix2.cols = 3; test6cMatrix2.elements = test6Matrix2Elements;
	double   test6Matrix3Elements[6];
	t_matrix test6Matrix3; test6Matrix3.rows = 2; test6Matrix3.cols = 3; test6Matrix3.elements = test6Matrix3Elements;
	double   test6Matrix4Elements[6] = {101,144,246,1045,1446,1916};
	t_matrix test6Matrix4; test6Matrix4.rows = 2; test6Matrix4.cols = 3; test6Matrix4.elements = test6Matrix4Elements;
	int test6Return = matrix_mult(&test6cMatrix1, &test6cMatrix2, &test6Matrix3);
	assert_svalue(OK_OPERATION , test6Return,                      "multi 2x2 * 2x3  return ");
	assert_double(0, compare_matrix(&test6Matrix4, &test6Matrix3), "multi 2x2 * 2x3");

	//test7
	double   test7Matrix1Elements[16] = {   0.0, -1.2, 8.969,      0,
	                                      78.52,  -17,     5,  9.396,
										  -3.14,   65, 8.969, -9.369,
										      8, -1.2,  3.14,  9.369};
	t_matrix test7cMatrix1; test7cMatrix1.rows = 4; test7cMatrix1.cols = 4; test7cMatrix1.elements = test7Matrix1Elements;
	double   test7Matrix2Elements[16] = {   0.0, -1.2, 8.969,      0,
	                                      78.52,  -17,     5,  9.396,
										  -3.14,   65, 8.969, -9.369,
										      8, -1.2,  3.14,  9.369};
	t_matrix test7cMatrix2; test7cMatrix2.rows = 4; test7cMatrix2.cols = 4; test7cMatrix2.elements = test7Matrix2Elements;
	double   test7Matrix3Elements[16];
	t_matrix test7Matrix3; test7Matrix3.rows = 4; test7Matrix3.cols = 4; test7Matrix3.elements = test7Matrix3Elements;
	double   test7Matrix4Elements[16] = {-122.38666,  603.385,	 74.442961,	 -95.305761,
 										  -1275.372,  508.5008,	 693.59432,	-118.545876,
										 5000.68534, -507.0042,	347.861641,	 438.931278,
  										   -29.1316,  203.6572,	 123.33332,	 47.084301};
	t_matrix test7Matrix4; test7Matrix4.rows = 4; test7Matrix4.cols = 4; test7Matrix4.elements = test7Matrix4Elements;
	int test7Return = matrix_mult(&test7cMatrix1, &test7cMatrix2, &test7Matrix3);
	assert_svalue(OK_OPERATION , test7Return,                      "multi 4x4 * 4x4  return ");
	assert_double(0, compare_matrix(&test7Matrix4, &test7Matrix3), "multi 4x4 * 4x4");
}


static void matrix_transpose_test()
{
	create_subtitle("matrix_transpose_test");

	//test1 ERR_MATRIX_TRANSP_ROW different rows
	t_matrix test1Matrix1; test1Matrix1.rows = 1; test1Matrix1.cols = 1;
	t_matrix test1Matrix2; test1Matrix2.rows = 2; test1Matrix2.cols = 1;
	int test1Return1 = matrix_transpose(&test1Matrix1, &test1Matrix2);
	assert_svalue(ERR_MATRIX_TRANSP_ROW, test1Return1,  "test transpose 1x1 2x1 (test ERR_MATRIX_TRANSP_ROW)");

	//test2 ERR_MATRIX_TRANSP_COL different cols
	t_matrix test2Matrix1; test2Matrix1.rows = 1; test2Matrix1.cols = 1;
	t_matrix test2Matrix2; test2Matrix2.rows = 1; test2Matrix2.cols = 2;
	int test2Return1 = matrix_transpose(&test2Matrix1, &test2Matrix2);
	assert_svalue(ERR_MATRIX_TRANSP_COL, test2Return1,  "test transpose 1x1 1x2 (test ERR_MATRIX_TRANSP_ROW)");

	//test 3   1x1
	double   test3Matrix1Elements[1] = {2};
	t_matrix test3Matrix1; test3Matrix1.rows = 1; test3Matrix1.cols = 1; test3Matrix1.elements = test3Matrix1Elements;
	double   test3Matrix2Elements[1] = {-8};
	t_matrix test3Matrix2; test3Matrix2.rows = 1; test3Matrix2.cols = 1; test3Matrix2.elements = test3Matrix2Elements;
	matrix_transpose(&test3Matrix1, &test3Matrix2);
	assert_svalue(2, test3Matrix2Elements[0], "transpose 1x1");

	//test 4   2x2
	double   test4Matrix1Elements[4] = {1,2,3,4};
	t_matrix test4Matrix1; test4Matrix1.rows = 2; test4Matrix1.cols = 2; test4Matrix1.elements = test4Matrix1Elements;
	double   test4Matrix2Elements[4] = {-1,-1,-1,-1};
	t_matrix test4Matrix2; test4Matrix2.rows = 2; test4Matrix2.cols = 2; test4Matrix2.elements = test4Matrix2Elements;
	matrix_transpose(&test4Matrix1, &test4Matrix2);
	double   test4Matrix3Elements[4] = {1, 3, 2, 4};
	t_matrix test4Matrix3; test4Matrix3.rows = 2; test4Matrix3.cols = 2; test4Matrix3.elements = test4Matrix3Elements;
	assert_svalue(0, compare_matrix(&test4Matrix3, &test4Matrix2), "transpose 2x2");

	//test 4 double value
	double   test5Matrix1Elements[4] = {1.5,2.4,0.42,0.567};
	t_matrix test5Matrix1; test5Matrix1.rows = 2; test5Matrix1.cols = 2; test5Matrix1.elements = test5Matrix1Elements;
	double   test5Matrix2Elements[4] = {-1,-1,-1,-1};
	t_matrix test5Matrix2; test5Matrix2.rows = 2; test5Matrix2.cols = 2; test5Matrix2.elements = test5Matrix2Elements;
	matrix_transpose(&test5Matrix1, &test5Matrix2);
	double   test5Matrix3Elements[4] = {1.5,0.42,2.4,0.567};
	t_matrix test5Matrix3; test5Matrix3.rows = 2; test5Matrix3.cols = 2; test5Matrix3.elements = test5Matrix3Elements;
	assert_svalue(0, compare_matrix(&test5Matrix3, &test5Matrix2), "transpose 2x2 doubles");
}

static void matrix_inverse_4x4_test()
{
#define MATRIX_SIZE 16

	create_subtitle("matrix_inverse_4x4_test");

	//test 1 determinant is 0 ERR
	double test1Matrix1Elements[MATRIX_SIZE] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	t_matrix test1Matrix1;
	test1Matrix1.rows = 4; test1Matrix1.cols = 4; test1Matrix1.elements = test1Matrix1Elements;
	int test1Return = matrix_inverse_4x4(&test1Matrix1, NULL);
	assert_svalue(ERR_DETERMINANT_ZERO, test1Return, "test1: determinante is 0 ERR");


	//test 2 valid inverted matrix
	double test2Matrix1Elements[MATRIX_SIZE] = {-5,  2, 6,-8,
                                                 1, -5, 1, 8,
                                                 7,  7,-6,-7,
                                                 1, -3, 7, 4};
	t_matrix test2Matrix1;
	test2Matrix1.rows = 4; test2Matrix1.cols = 4; test2Matrix1.elements = test2Matrix1Elements;

	double test2Matrix2Elements[MATRIX_SIZE];
	t_matrix test2Matrix2;
	test2Matrix2.rows = 4; test2Matrix2.cols = 4; test2Matrix2.elements = test2Matrix2Elements;

	double test2Matrix3Elements[MATRIX_SIZE] = { 0.21805,   0.45113,  0.24060, -0.04511,
                                                 -0.80827, -1.45677, -0.44361,  0.52068,
                                                 -0.07895, -0.22368, -0.05263,  0.19737,
                                                 -0.52256, -0.81391, -0.30075,  0.30639};
	t_matrix test2Matrix3;
	test2Matrix3.rows = 4; test2Matrix3.cols = 4; test2Matrix3.elements = test2Matrix3Elements;
	matrix_inverse_4x4(&test2Matrix1, &test2Matrix2);
	assert_svalue(0, compare_matrix(&test2Matrix2, &test2Matrix3), "test2: valid invert matrix");

	//test 3 valid inverted matrix

	double test3Matrix1Elements[MATRIX_SIZE] = {1, 0,   0, 0,
												0, 0.5, 0, 0,
												0, 0,   1, 0,
												0, 0,   0, 1};
	t_matrix test3Matrix1;
	test3Matrix1.rows = 4; test3Matrix1.cols = 4; test3Matrix1.elements = test3Matrix1Elements;

	double test3Matrix2Elements[MATRIX_SIZE];
	t_matrix test3Matrix2;
	test3Matrix2.rows = 4; test3Matrix2.cols = 4; test3Matrix2.elements = test3Matrix2Elements;

	double test3Matrix3Elements[MATRIX_SIZE] = {1, 0, 0, 0,
												0, 2, 0, 0,
												0, 0, 1, 0,
												0, 0, 0, 1};
	t_matrix test3Matrix3;
	test3Matrix3.rows = 4; test3Matrix3.cols = 4; test3Matrix3.elements = test3Matrix3Elements;

	int test3Return = matrix_inverse_4x4(&test3Matrix1, &test3Matrix2);
	assert_svalue(OK_OPERATION, test3Return, "test3: return value");
	assert_svalue(0, compare_matrix(&test3Matrix2, &test3Matrix3), "test3: valid invert matrix 0.5 and 2");

	//
}


void matrix_operations_test(int argc, char **argv)
{
	if (argc != 1 &&  strcmp(argv[1], "matrix_operations_test") != 0)
		return ;

	create_title("matrix_operations_test");

	matrix_addition_test();
	matrix_subtraction_test();
	matrix_negation_test();
	matrix_mult_scalar_test();
	matrix_div_scalar_test();
	matrix_get_magnitude_test();
	matrix_normalization_test();
	matrix_dot_test();
	matrix_cross_test();
	matrix_mult_test();
	matrix_transpose_test();
	matrix_inverse_4x4_test();

}