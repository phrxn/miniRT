#include "ray_test.h"
#include "ray.h"
#include "matrix_alloc.h"
#include <string.h>

#include "assertz.h"
#include "compare.h"

static void create_ray_test()
{
     create_subtitle("create_ray_test");

    //test1: Computing a point from a distance
    t_matrix *test1Point = matrix_create_point(2,3,4);
    t_matrix *test1Vector = matrix_create_point(1,0,0);

    t_ray    *ray = create_ray(test1Point, test1Vector);

    destroy_matrix(&test1Point);
    destroy_matrix(&test1Vector);
    destroy_ray(&ray);

    assert_utils_print_ok("create_ray and destroy_ray");

}


static void    position_test()
{
    create_subtitle("position_test");


    //test1: Computing a point from a distance
    t_matrix *test1Point = matrix_create_point(2,3,4);
    t_matrix *test1Vector = matrix_create_vector(1,0,0);

    t_ray    *ray = create_ray(test1Point, test1Vector);

    t_matrix *test1Position1 = position(ray, 0);
    assert_svalue(2, 	    test1Position1->elements[X], "test1Position1->elements[X]");
    assert_svalue(3, 	    test1Position1->elements[Y], "test1Position1->elements[Y]");
    assert_svalue(4,        test1Position1->elements[Z], "test1Position1->elements[Z]");
    assert_svalue(POINT, 	test1Position1->elements[W], "test1Position1->elements[W]");
    destroy_matrix(&test1Position1);
    assert_utils_separator();

    t_matrix *test1Position2 = position(ray, 1);
    assert_svalue(3, 	    test1Position2->elements[X], "test1Position2->elements[X]");
    assert_svalue(3, 	    test1Position2->elements[Y], "test1Position2->elements[Y]");
    assert_svalue(4,        test1Position2->elements[Z], "test1Position2->elements[Z]");
    assert_svalue(POINT, 	test1Position2->elements[W], "test1Position2->elements[W]");
    destroy_matrix(&test1Position2);
    assert_utils_separator();

    t_matrix *test1Position3 = position(ray, -1);
    assert_svalue(1, 	    test1Position3->elements[X], "test1Position3->elements[X]");
    assert_svalue(3, 	    test1Position3->elements[Y], "test1Position3->elements[Y]");
    assert_svalue(4,        test1Position3->elements[Z], "test1Position3->elements[Z]");
    assert_svalue(POINT, 	test1Position3->elements[W], "test1Position3->elements[W]");
    destroy_matrix(&test1Position3);
    assert_utils_separator();

    t_matrix *test1Position4 = position(ray, 2.5);
    assert_double(0,   compare_double(4.5, test1Position4->elements[X]), "test1Position4->elements[X]");
    assert_svalue(3, 	    test1Position4->elements[Y], "test1Position4->elements[Y]");
    assert_svalue(4,        test1Position4->elements[Z], "test1Position4->elements[Z]");
    assert_svalue(POINT, 	test1Position4->elements[W], "test1Position4->elements[W]");
    destroy_matrix(&test1Position4);

    destroy_matrix(&test1Point);
    destroy_matrix(&test1Vector);
    destroy_ray(&ray);


}

void ray_test(int argc, char **argv)
{
	if (argc != 1 &&  strcmp(argv[1], "ray_test") != 0)
		return ;

	create_title("ray_test");
    create_ray_test();
    position_test();
}
