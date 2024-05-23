#include "canvas_test.h"
#include "matrix_operations_test.h"
#include "matrix_test.h"
#include "matrix_fill_test.h"
#include "ray_test.h"
#include "array_test.h"
#include "intersect_sphere_test.h"
#include "hit_test.h"
#include "transform_test.h"
#include "shape_test.h"
#include "normal_test.h"
#include "reflect_test.h"
#include "lighting_test.h"
#include "world_test.h"
#include "intersect_world_test.h"
#include "prepare_computations_test.h"
#include "shade_hit_test.h"
#include "lexer_test.h"
#include "view_transform_test.h"
#include "intersect_plane_test.h"
#include "shadow_test.h"
#include "syntax_elements_test.h"
#include "select_element_test.h"
#include "ft_atoi_2_test.h"
#include "ft_atof_test.h"
#include "matrix_rotation_convert_test.h"

int main(int argc, char *argv[])
{
	/*!! nao comentar!!*/
	matrix_test(argc, argv);


	matrix_operations_test(argc, argv);
	canvas_test(argc, argv);
	matrix_fill_test(argc, argv);
	ray_test(argc, argv);

	array_test(argc, argv);

	intersect_sphere_test(argc, argv);

	hit_test(argc, argv);

	transform_test(argc, argv);

	shape_test(argc, argv);

	shape_sphere_test(argc, argv);

	normal_test(argc, argv);

	reflect_test(argc, argv);

	lighting_test(argc, argv);

	world_test(argc, argv);

	intersect_world_test(argc, argv);

	prepare_computations_test(argc, argv);

	shade_hit_test(argc, argv);

	lexer_test(argc, argv);

	view_transform_test(argc, argv);

	intersect_plane_test(argc, argv);

	shadow_test(argc, argv);

	//syntax_elements_test.
	syntax_ambient_test(argc, argv);
	syntax_camera_test(argc, argv);
	syntax_cylinder_test(argc, argv);
	syntax_light_test(argc, argv);
	syntax_plane_test(argc, argv);
	syntax_sphere_test(argc, argv);

	select_element_test(argc, argv);

	ft_atoi_2_test(argc, argv);

	ft_atof_test(argc, argv);

	matrix_rotation_convert_test(argc, argv);

	return 0;
}
