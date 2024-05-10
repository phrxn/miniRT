#include "lighting_test.h"
#include "lighting.h"
#include "material.h"
#include "matrix.h"
#include "matrix_alloc.h"
#include "light.h"

#include "assertz.h"

#include "world.h"

#include "compare.h"

#include <string.h>

#include <math.h>

static void lighting_test1()
{
    create_subtitle("lighting_test1");

    t_material material;
    fill_material(&material);
    t_matrix    *position = matrix_create_point(0,0,0);
    t_color     light_color; fill_color(&light_color, 1, 1, 1);

    // test1
    t_lighting_params test1lightParams;
    t_matrix *test1Eyev =      matrix_create_vector(0,0,-1);
    t_matrix *test1normalv   = matrix_create_vector(0,0,-1);
    t_light  *test1light =     create_light(&light_color, 0, 0, -10);

    test1lightParams.eyev = test1Eyev;
    test1lightParams.light = test1light;
    test1lightParams.material = &material;
    test1lightParams.normalv = test1normalv;
    test1lightParams.point = position;
    t_color   test1Result = lighting(&test1lightParams);
    t_color   test1Expected; fill_color(&test1Expected, 1.9, 1.9, 1.9);

    assert_svalue(0, compare_color(&test1Expected, &test1Result), "test1 1.9, 1.9, 1.9");

    destroy_matrix(&test1Eyev);
    destroy_matrix(&test1normalv);
    destroy_light(&test1light);
    assert_utils_separator();

    // test2
    double test2Value = sqrt(2)/2;
    t_lighting_params test2lightParams;
    t_matrix *test2Eyev =      matrix_create_vector(0,test2Value,-test2Value);
    t_matrix *test2normalv   = matrix_create_vector(0,         0,         -1);
    t_light  *test2light =     create_light(&light_color, 0, 0, -10);

    test2lightParams.eyev = test2Eyev;
    test2lightParams.light = test2light;
    test2lightParams.material = &material;
    test2lightParams.normalv = test2normalv;
    test2lightParams.point = position;
    t_color   test2Result = lighting(&test2lightParams);
    t_color   test2Expected; fill_color(&test2Expected, 1, 1, 1);

    assert_svalue(0, compare_color(&test2Expected, &test2Result), "test2 1.0, 1.0, 1.0");

    destroy_matrix(&test2Eyev);
    destroy_matrix(&test2normalv);
    destroy_light(&test2light);
    assert_utils_separator();

    // test3
    t_lighting_params test3lightParams;
    t_matrix *test3Eyev =      matrix_create_vector(0, 0, -1);
    t_matrix *test3normalv   = matrix_create_vector(0, 0, -1);
    t_light  *test3light =     create_light(&light_color, 0, 10, -10);

    test3lightParams.eyev = test3Eyev;
    test3lightParams.light = test3light;
    test3lightParams.material = &material;
    test3lightParams.normalv = test3normalv;
    test3lightParams.point = position;
    t_color   test3Result = lighting(&test3lightParams);
    t_color   test3Expected; fill_color(&test3Expected, 0.7364, 0.7364, 0.7364);

    assert_svalue(0, compare_color(&test3Expected, &test3Result), "test3 0.7364, 0.7364, 0.7364");

    destroy_matrix(&test3Eyev);
    destroy_matrix(&test3normalv);
    destroy_light(&test3light);
    assert_utils_separator();


    // test4
    double test4Value = sqrt(2)/2;
    t_lighting_params test4lightParams;
    t_matrix *test4Eyev =      matrix_create_vector(0,  -test4Value,  -test4Value);
    t_matrix *test4normalv   = matrix_create_vector(0,           0,           -1);
    t_light  *test4light =     create_light(&light_color, 0, 10, -10);

    test4lightParams.eyev = test4Eyev;
    test4lightParams.light = test4light;
    test4lightParams.material = &material;
    test4lightParams.normalv = test4normalv;
    test4lightParams.point = position;
    t_color   test4Result = lighting(&test4lightParams);
    t_color   test4Expected; fill_color(&test4Expected, 1.6364, 1.6364, 1.6364);

    assert_svalue(0, compare_color(&test4Expected, &test4Result), "test4 1.6364, 1.6364, 1.6364");

    destroy_matrix(&test4Eyev);
    destroy_matrix(&test4normalv);
    destroy_light(&test4light);
    assert_utils_separator();


    // test5
    t_lighting_params test5lightParams;
    t_matrix *test5Eyev    = matrix_create_vector(0, 0, -1);
    t_matrix *test5normalv = matrix_create_vector(0, 0, -1);
    t_light  *test5light   = create_light(&light_color, 0, 0, 10);

    test5lightParams.eyev = test5Eyev;
    test5lightParams.light = test5light;
    test5lightParams.material = &material;
    test5lightParams.normalv = test5normalv;
    test5lightParams.point = position;
    t_color   test5Result = lighting(&test5lightParams);
    t_color   test5Expected; fill_color(&test5Expected, 0.1, 0.1, 0.1);

    assert_svalue(0, compare_color(&test5Expected, &test5Result), "test5 0.1, 0.1, 0.1");

    destroy_matrix(&test5Eyev);
    destroy_matrix(&test5normalv);
    destroy_light(&test5light);
    assert_utils_separator();





    destroy_matrix(&position);
}

void    lighting_test(int argc, char **argv)
{
    if (argc != 1 &&  strcmp(argv[1], "lighting_test") != 0)
		return ;

	create_title("lighting_test");

    lighting_test1();
}