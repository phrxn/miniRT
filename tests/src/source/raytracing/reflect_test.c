#include "reflect_test.h"
#include "reflect.h"
#include "assertz.h"
#include "matrix.h"
#include "matrix_alloc.h"

#include <string.h>

#include "compare.h"

#include <math.h>

static void reflect_test1()
{
    create_subtitle("reflect_test1");

    //test1
    t_matrix *test1VectorIn     = matrix_create_vector(1, -1, 0);
    t_matrix *test1VectorNormal = matrix_create_vector(0,  1, 0);
    t_matrix *test1Reflect      = reflect(test1VectorIn, test1VectorNormal);
    t_matrix *test1Expected     = matrix_create_vector(1,1,0);
    assert_svalue(0, compare_matrix(test1Expected, test1Reflect), "test1  1,-1,0");

    destroy_matrix(&test1VectorIn);
    destroy_matrix(&test1VectorNormal);
    destroy_matrix(&test1Reflect);
    destroy_matrix(&test1Expected);

    //test1
    double test2Value = sqrt(2)/2;
    t_matrix *test2VectorIn     = matrix_create_vector(0, -1, 0);
    t_matrix *test2VectorNormal = matrix_create_vector(test2Value,  test2Value, 0);
    t_matrix *test2Reflect      = reflect(test2VectorIn, test2VectorNormal);
    t_matrix *test2Expected     = matrix_create_vector(1,0,0);
    assert_svalue(0, compare_matrix(test2Expected, test2Reflect), "test2  1,-1,0");

    destroy_matrix(&test2VectorIn);
    destroy_matrix(&test2VectorNormal);
    destroy_matrix(&test2Reflect);
    destroy_matrix(&test2Expected);
}


void reflect_test(int argc, char **argv)
{
	if (argc != 1 &&  strcmp(argv[1], "reflect_test") != 0)
		return ;

	create_title("reflect_test");
    reflect_test1();
}