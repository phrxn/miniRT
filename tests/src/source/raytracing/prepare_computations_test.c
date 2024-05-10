#include "prepare_computations_test.h"
#include "prepare_computations.h"

#include "shape.h"
#include "intersect.h"
#include "intersect_utils.h"
#include "matrix_alloc.h"
#include "matrix_fill.h"
#include "ray.h"
#include "matrix_fill.h"

#include "assertz.h"
#include <string.h>

#include "compare.h"

void	create_pre_computations_test()
{
	create_subtitle("create_pre_computations_test");

	//test1
	t_shape *test1Shape = create_shape(TYPE_SPHERE);
	t_inter *test1Inter = create_intersection(3, test1Shape);
	t_matrix *test1Origin = matrix_create_point(1,2,3);
	t_matrix *test1Direction = matrix_create_vector(4,5,6);
	t_ray	 *test1Ray = create_ray(test1Origin, test1Direction);
	t_prepare_computations *pre = create_pre_computations(test1Inter, test1Ray);


	destroy_shape(&test1Shape);
	destroy_intersection(&test1Inter);
	destroy_matrix(&test1Origin);
	destroy_matrix(&test1Direction);
	destroy_ray(&test1Ray);
	destroy_pre_computations(&pre);
	assert_utils_print_ok("create and destroy pre_computations");

}

void	tests()
{
	create_subtitle("tests");

	//test1
	t_shape *test1Shape = create_shape(TYPE_SPHERE);
	t_inter *test1Inter = create_intersection(4, test1Shape);
	t_matrix *test1Origin = matrix_create_point(0, 0, -5);
	t_matrix *test1Direction = matrix_create_vector(0, 0, 1);
	t_ray	 *test1Ray = create_ray(test1Origin, test1Direction);
	t_prepare_computations *test1Pre = create_pre_computations(test1Inter, test1Ray);
	assert_svalue(FALSE, test1Pre->inside, "hit inside == false");

	destroy_shape(&test1Shape);
	destroy_intersection(&test1Inter);
	destroy_matrix(&test1Origin);
	destroy_matrix(&test1Direction);
	destroy_ray(&test1Ray);
	destroy_pre_computations(&test1Pre);
	assert_utils_separator();

	//test2
	t_shape *test2Shape = create_shape(TYPE_SPHERE);
	fill_material(&test2Shape->material);
	test2Shape->id = 42;

	t_inter *test2Inter = create_intersection(1, test2Shape);
	t_matrix *test2Origin = matrix_create_point(0, 0, 0);
	t_matrix *test2Direction = matrix_create_vector(0, 0, 1);
	t_ray	 *test2Ray = create_ray(test2Origin, test2Direction);
	t_prepare_computations *test2Pre = create_pre_computations(test2Inter, test2Ray);
	t_matrix *test2ExpectedPoint = matrix_create_point(0,0,1);
	t_matrix *test2ExpectedEyev  = matrix_create_vector(0,0,-1);
	t_matrix *test2ExpectedNormalv  = matrix_create_vector(0,0,-1);


	assert_svalue(TRUE, test2Pre->inside, "hit inside == true");
	assert_svalue(0, compare_matrix(test2ExpectedPoint, test2Pre->point), "test2 point");
	assert_svalue(0, compare_matrix(test2ExpectedEyev, test2Pre->eyev), "test2 eyev");
	assert_svalue(0, compare_matrix(test2ExpectedNormalv, test2Pre->normalv), "test2 normalv");

	destroy_shape(&test2Shape);
	destroy_intersection(&test2Inter);
	destroy_matrix(&test2Origin);
	destroy_matrix(&test2Direction);
	destroy_ray(&test2Ray);
	destroy_pre_computations(&test2Pre);
	destroy_matrix(&test2ExpectedPoint);
	destroy_matrix(&test2ExpectedEyev);
	destroy_matrix(&test2ExpectedNormalv);
	assert_utils_separator();


	//test3 test if the copy is working
	t_shape  *test3Shape1 = create_shape(TYPE_SPHERE);
	test3Shape1->id                        = 2;
	test3Shape1->material.ambient          = 4;
	test3Shape1->material.color.red        = 5;
	test3Shape1->material.color.green      = 6;
	test3Shape1->material.color.blue       = 7;
	t_sphere *test3Shape1Sphere = (t_sphere*) test3Shape1->shape;
	test3Shape1Sphere->center->elements[X] = 8;
	test3Shape1Sphere->center->elements[Y] = 9;
	test3Shape1Sphere->center->elements[Z] = 10;
	test3Shape1Sphere->center->elements[W] = 1;
	test3Shape1Sphere->radius              = 12;
	matrix_fill_scaling(test3Shape1->transformation, 13, 14, 15);
	test3Shape1->type = TYPE_SPHERE;

	t_inter  *test3Inter = create_intersection(4, test3Shape1);

	t_matrix *test3Origin = matrix_create_point(0, 0, -5);
	t_matrix *test3Direction = matrix_create_vector(0, 0, 1);
	t_ray	 *test3Ray = create_ray(test3Origin, test3Direction);
	t_prepare_computations *test3Pre = create_pre_computations(test3Inter, test3Ray);

	t_shape  *test3ShapeResult = test3Pre->shape;

	assert_uvalue(2, test3ShapeResult->id, "test3ShapeResult->id");
	assert_double(4, test3ShapeResult->material.ambient, "test3ShapeResult->material.ambient");
	assert_double(5, test3ShapeResult->material.color.red, "test3ShapeResult->material.color.red");
	assert_double(6, test3ShapeResult->material.color.green, "test3ShapeResult->material.color.green");
	assert_double(7, test3ShapeResult->material.color.blue, "test3ShapeResult->material.color.blue");
	t_sphere *test3ShapeSphereResult = (t_sphere*) test3ShapeResult->shape;
	t_matrix *test3ShapeSphereCenterResult = matrix_create_point(8,9,10);
	assert_svalue(0, compare_matrix(test3ShapeSphereCenterResult, test3ShapeSphereResult->center), "test3ShapeSphereResult->center");
	assert_double(12, test3ShapeSphereResult->radius, "test3ShapeSphereResult->radius");
	t_matrix *test3ShapeTransformExpected = matrix_create_scaling(13, 14, 15);
	assert_svalue(0, compare_matrix(test3ShapeTransformExpected, test3ShapeResult->transformation), "test3ShapeResult->transformation");
	assert_svalue(TYPE_SPHERE, test3ShapeResult->type, "test3ShapeResult->type");


	destroy_shape(&test3Shape1);
	destroy_intersection(&test3Inter);
	destroy_matrix(&test3Origin);
	destroy_matrix(&test3Direction);
	destroy_ray(&test3Ray);
	destroy_pre_computations(&test3Pre);
	destroy_matrix(&test3ShapeSphereCenterResult);
	destroy_matrix(&test3ShapeTransformExpected);






	assert_utils_separator();



}

void	prepare_computations_test(int argc, char **argv)
{
	if (argc != 1 &&  strcmp(argv[1], "prepare_computations_test") != 0)
		return ;
	create_title("prepare_computations_test");

	create_pre_computations_test();
	tests();
}