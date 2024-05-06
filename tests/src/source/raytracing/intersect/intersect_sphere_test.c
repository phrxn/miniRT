/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere_test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:14:34 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/06 20:24:01 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect_sphere_test.h"
#include "intersect_sphere.h"
#include "intersect.h"
#include "intersect_utils.h"
#include "matrix.h"
#include "matrix_alloc.h"
#include "ray.h"

#include <string.h>

#include "assertz.h"

static void intersect_sphere_test1()
{
    create_subtitle("intersect_sphere_test1");

    t_matrix *identity = matrix_create_identity_4x4();

    //test1
        // ray
        t_matrix    *test1Point1 = matrix_create_point(0,0,-5);
        t_matrix    *test1Vector1 = matrix_create_vector(0,0,1);
        t_ray       *test1Ray1    = create_ray(test1Point1, test1Vector1);

        //the sphere
        t_matrix    *test1CenterSphere = matrix_create_point(0,0,0);
        t_sphere    test1Sphere; test1Sphere.center = test1CenterSphere; test1Sphere.radius = 1;

        t_shape test1Shape; test1Shape.id = 1;
                test1Shape.transformation = identity;
                test1Shape.type = TYPE_SPHERE;
                test1Shape.shape = &test1Sphere;
        
        // t_list
        t_list *test1List = intersect_sphere(&test1Shape, test1Ray1);

        assert_svalue(2, ft_lstsize(test1List), "test1List size");
        assert_svalue(1, ((t_inter*)test1List->content)->shape->id       , "intersection 1 shape id");
        assert_svalue(1, ((t_inter*)test1List->next->content)->shape->id , "intersection 2 shape id");
        assert_double(4, ((t_inter*)test1List->content)->t               , "intersection 1 t");
        assert_double(6, ((t_inter*)test1List->next->content)->t         , "intersection 2 t");

        ft_lstclear(&test1List, destroy_intersection2);

        destroy_matrix(&test1Point1);
        destroy_matrix(&test1Vector1);
        destroy_ray(&test1Ray1);
        destroy_matrix(&test1CenterSphere);
        assert_utils_separator();

    //test2
        // ray
        t_matrix    *test2Point1 = matrix_create_point(0,1,-5);
        t_matrix    *test2Vector1 = matrix_create_vector(0,0,1);
        t_ray       *test2Ray1    = create_ray(test2Point1, test2Vector1);

        //the sphere
        t_matrix    *test2CenterSphere = matrix_create_point(0,0,0);
        t_sphere    test2Sphere; test2Sphere.center = test2CenterSphere; test2Sphere.radius = 1;

        t_shape test2Shape; test2Shape.id = 3;
                test2Shape.transformation = identity;
                test2Shape.type = TYPE_SPHERE;
                test2Shape.shape = &test2Sphere;
        
        // t_list
        t_list *test2List = intersect_sphere(&test2Shape, test2Ray1);

        assert_svalue(2, ft_lstsize(test2List), "test2List size");
        assert_svalue(3, ((t_inter*)test2List->content)->shape->id       , "test2 intersection 1 shape id");
        assert_svalue(3, ((t_inter*)test2List->next->content)->shape->id , "test2 intersection 2 shape id");
        assert_double(5, ((t_inter*)test2List->content)->t               , "test2 intersection 1 t");
        assert_double(5, ((t_inter*)test2List->next->content)->t         , "test2 intersection 2 t");

        ft_lstclear(&test2List, destroy_intersection2);

        destroy_matrix(&test2Point1);
        destroy_matrix(&test2Vector1);
        destroy_ray(&test2Ray1);
        destroy_matrix(&test2CenterSphere);
        assert_utils_separator();

    //test3
        // ray
        t_matrix    *test3Point1 = matrix_create_point(0,-1,-5);
        t_matrix    *test3Vector1 = matrix_create_vector(0,0,1);
        t_ray       *test3Ray1    = create_ray(test3Point1, test3Vector1);

        //the sphere
        t_matrix    *test3CenterSphere = matrix_create_point(0,0,0);
        t_sphere    test3Sphere; test3Sphere.center = test3CenterSphere; test3Sphere.radius = 1;

        t_shape test3Shape; test3Shape.id = 3;
                test3Shape.transformation = identity;
                test3Shape.type = TYPE_SPHERE;
                test3Shape.shape = &test3Sphere;
        
        // t_list
        t_list *test3List = intersect_sphere(&test3Shape, test3Ray1);

        assert_svalue(2, ft_lstsize(test3List), "test3List size");
        assert_svalue(3, ((t_inter*)test3List->content)->shape->id       , "test3 intersection 1 shape id");
        assert_svalue(3, ((t_inter*)test3List->next->content)->shape->id , "test3 intersection 2 shape id");
        assert_double(5, ((t_inter*)test3List->content)->t               , "test3 intersection 1 t");
        assert_double(5, ((t_inter*)test3List->next->content)->t         , "test3 intersection 2 t");

        ft_lstclear(&test3List, destroy_intersection2);

        destroy_matrix(&test3Point1);
        destroy_matrix(&test3Vector1);
        destroy_ray(&test3Ray1);
        destroy_matrix(&test3CenterSphere);
        assert_utils_separator();

    //test4
        // ray
        t_matrix    *test4Point1 = matrix_create_point(0, 2,-5);
        t_matrix    *test4Vector1 = matrix_create_vector(0,0,1);
        t_ray       *test4Ray1    = create_ray(test4Point1, test4Vector1);

        //the sphere
        t_matrix    *test4CenterSphere = matrix_create_point(0,0,0);
        t_sphere    test4Sphere; test4Sphere.center = test4CenterSphere; test4Sphere.radius = 1;

        t_shape test4Shape; test4Shape.id = 3;
                test4Shape.transformation = identity;
                test4Shape.type = TYPE_SPHERE;
                test4Shape.shape = &test4Sphere;
        
        // t_list
        t_list *test4List = intersect_sphere(&test4Shape, test4Ray1);

        assert_svalue(0, ft_lstsize(test4List), "test4List size");

        ft_lstclear(&test4List, destroy_intersection2);

        destroy_matrix(&test4Point1);
        destroy_matrix(&test4Vector1);
        destroy_ray(&test4Ray1);
        destroy_matrix(&test4CenterSphere);

    //test5
        // ray
        t_matrix    *test5Point1 = matrix_create_point(0, 0, 0);
        t_matrix    *test5Vector1 = matrix_create_vector(0,0,1);
        t_ray       *test5Ray1    = create_ray(test5Point1, test5Vector1);

        //the sphere
        t_matrix    *test5CenterSphere = matrix_create_point(0,0,0);
        t_sphere    test5Sphere; test5Sphere.center = test5CenterSphere; test5Sphere.radius = 1;

        t_shape test5Shape; test5Shape.id = 7;
                test5Shape.transformation = identity;
                test5Shape.type = TYPE_SPHERE;
                test5Shape.shape = &test5Sphere;
        
        // t_list
        t_list *test5List = intersect_sphere(&test5Shape, test5Ray1);

        assert_svalue(2, ft_lstsize(test5List), "test5List size");
        assert_svalue(7, ((t_inter*)test5List->content)->shape->id       , "test5 intersection 1 shape id");
        assert_svalue(7, ((t_inter*)test5List->next->content)->shape->id , "test5 intersection 2 shape id");
        assert_double(-1, ((t_inter*)test5List->content)->t               , "test5 intersection 1 t");
        assert_double(1, ((t_inter*)test5List->next->content)->t         , "test5 intersection 2 t");

        ft_lstclear(&test5List, destroy_intersection2);

        destroy_matrix(&test5Point1);
        destroy_matrix(&test5Vector1);
        destroy_ray(&test5Ray1);
        destroy_matrix(&test5CenterSphere);
        assert_utils_separator();

    //test6
        // ray
        t_matrix    *test6Point1 = matrix_create_point(0, 0, -5);
        t_matrix    *test6Vector1 = matrix_create_vector(0,0,1);
        t_ray       *test6Ray1    = create_ray(test6Point1, test6Vector1);
        t_matrix    *test6Transf  = matrix_create_scaling(2,2,2);

        //the sphere
        t_matrix    *test6CenterSphere = matrix_create_point(0,0,0);
        t_sphere    test6Sphere; test6Sphere.center = test6CenterSphere; test6Sphere.radius = 1;

        t_shape test6Shape; test6Shape.id = 63;
                test6Shape.transformation = test6Transf;
                test6Shape.type = TYPE_SPHERE;
                test6Shape.shape = &test6Sphere;
        
        // t_list
        t_list *test6List = intersect_sphere(&test6Shape, test6Ray1);

        assert_svalue(2, ft_lstsize(test6List), "test6List size");
        assert_svalue(63, ((t_inter*)test6List->content)->shape->id       , "test6 intersection 1 shape id");
        assert_svalue(63, ((t_inter*)test6List->next->content)->shape->id , "test6 intersection 2 shape id");
        assert_double(3, ((t_inter*)test6List->content)->t               , "test6 intersection 1 t");
        assert_double(7, ((t_inter*)test6List->next->content)->t         , "test6 intersection 2 t");

        ft_lstclear(&test6List, destroy_intersection2);

        destroy_matrix(&test6Point1);
        destroy_matrix(&test6Vector1);
        destroy_ray(&test6Ray1);
        destroy_matrix(&test6Transf);
        destroy_matrix(&test6CenterSphere);
        assert_utils_separator();





    destroy_matrix(&identity);
}


void	intersect_sphere_test(int argc, char **argv)
{
	if (argc != 1 &&  strcmp(argv[1], "intersect_sphere_test") != 0)
		return ;
	intersect_sphere_test1();
}
