#include "create_ppm.h"
#include "ray.h"
#include "matrix.h"
#include "matrix_alloc.h"
#include "canvas.h"
#include "shape.h"
#include "matrix_operations.h"
#include "libft.h"
#include "intersect.h"
#include "intersect_utils.h"
#include "hit.h"
#include "world.h"
#include "camera.h"
#include "view_transform.h"
#include "matrix_utils.h"
#include "matrix_fill.h"
#include "light.h"

#include "dworld.h"

#include <math.h>

#define WIDHT    1200
#define HEIGHT   1080

static void create_inverted(t_matrix* normal, t_matrix *inverted)
{
	t_matrix	*tmp_inverted_matrix;

	tmp_inverted_matrix = matrix_create_inverse(normal);
	matrix_copy(tmp_inverted_matrix, inverted);
	destroy_matrix(&tmp_inverted_matrix);
}


static t_camera *start_camera()
{
	t_camera *camera = create_camera(WIDHT, HEIGHT, M_PI/2);
	t_matrix	*tmp_inverted_matrix;

	t_matrix *from = matrix_create_point(0, 10, -30);
	t_matrix *to   = matrix_create_point(0, 1, 0);
	t_matrix *up   = matrix_create_vector(0, 1, 0);

	t_matrix *transformation = view_transform(from , to, up);
	matrix_copy(transformation, camera->transformation);
	create_inverted(camera->transformation, camera->transformation_inv);


	destroy_matrix(&from);
	destroy_matrix(&to);
	destroy_matrix(&up);
	destroy_matrix(&transformation);

	return (camera);

	return (camera);
}


static void add_wall_and_floor(t_world *world)
{
	t_matrix	*tmp = matrix_create_identity_4x4();
	t_matrix	*tmp_inverted_matrix;

	double material_specular = 0;
	t_color material_color; material_color.red = 1; material_color.green = 0.9, material_color.blue = 0.9;

	//floor
	t_shape	*floor = create_shape(TYPE_PLANE);
	fill_material(&floor->material);
	matrix_fill_scaling(floor->transformation, 10,0.01,10);
	create_inverted(floor->transformation, floor->transformation_inv);
	floor->material.specular = material_specular;
	fill_color(&floor->material.color, material_color.red, material_color.green, material_color.blue);
	t_list *item_floor = ft_lstnew(floor);
	ft_lstadd_back(&world->shapes, item_floor);
\
	//left_wall
	t_shape	*left_wall = create_shape(TYPE_PLANE);
	fill_material(&left_wall->material);
	t_matrix	*left_wall_transl = matrix_create_translate(0,0,5);
	t_matrix	*left_wall_rot_y = matrix_create_rot_y(-M_PI/4);
	t_matrix	*left_wall_rot_x = matrix_create_rot_x(M_PI/2);
	t_matrix	*left_wall_scali = matrix_create_scaling(10, 0.01, 10);

	matrix_mult(left_wall_transl, left_wall_rot_y, left_wall->transformation);
	matrix_mult(left_wall->transformation, left_wall_rot_x, tmp);
	matrix_mult(tmp, left_wall_scali, left_wall->transformation);
	create_inverted(left_wall->transformation, left_wall->transformation_inv);
	fill_color(&left_wall->material.color, material_color.red, material_color.green, material_color.blue);
	left_wall->material.specular = material_specular;
	t_list *item_left_wall = ft_lstnew(left_wall);
	ft_lstadd_back(&world->shapes, item_left_wall);
	destroy_matrix(&left_wall_transl);
	destroy_matrix(&left_wall_rot_y);
	destroy_matrix(&left_wall_rot_x);
	destroy_matrix(&left_wall_scali);

	//right_wall
	t_shape	*right_wall = create_shape(TYPE_PLANE);
	fill_material(&right_wall->material);
	t_matrix	*right_wall_transl = matrix_create_translate(0,0,5);
	t_matrix	*right_wall_rot_y = matrix_create_rot_y(M_PI/4);
	t_matrix	*right_wall_rot_x = matrix_create_rot_x(M_PI/2);
	t_matrix	*right_wall_scali = matrix_create_scaling(10, 0.01, 10);

	matrix_mult(right_wall_transl, right_wall_rot_y, right_wall->transformation);
	matrix_mult(right_wall->transformation, right_wall_rot_x, tmp);
	matrix_mult(tmp, right_wall_scali, right_wall->transformation);
	create_inverted(right_wall->transformation, right_wall->transformation_inv);

	fill_color(&right_wall->material.color, material_color.red, material_color.green, material_color.blue);
	right_wall->material.specular = material_specular;
	t_list *item_right_wall = ft_lstnew(right_wall);
	ft_lstadd_back(&world->shapes, item_right_wall);
	destroy_matrix(&right_wall_transl);
	destroy_matrix(&right_wall_rot_y);
	destroy_matrix(&right_wall_rot_x);
	destroy_matrix(&right_wall_scali);

	destroy_matrix(&tmp);
}


static void add_sphere(t_world *w)
{

	//middle sphere
	t_shape	*middle = create_shape(TYPE_SPHERE);
	matrix_fill_translation(middle->transformation, 0, 0, 0);
	create_inverted(middle->transformation, middle->transformation_inv);

	fill_material(&middle->material);
	fill_color(&middle->material.color, 1, 0, 1);
	middle->material.diffuse = 0.7;
	middle->material.specular = 0.3;

	t_list *middle_item = ft_lstnew(middle);
	ft_lstadd_back(&w->shapes, middle_item);

	//right sphere
	t_shape	*right = create_shape(TYPE_SPHERE);

	t_matrix	*right_transl = matrix_create_translate(1.5, 0.5, -0.5);
	t_matrix	*right_scali = matrix_create_scaling(0.5, 0.5, 0.5);

	matrix_mult(right_transl, right_scali, right->transformation);
	create_inverted(right->transformation, right->transformation_inv);

	destroy_matrix(&right_transl);
	destroy_matrix(&right_scali);

	fill_material(&right->material);
	fill_color(&right->material.color, 0.5, 1, 0.1);
	right->material.diffuse = 0.7;
	right->material.specular = 0.3;

	t_list *right_item = ft_lstnew(right);
	ft_lstadd_back(&w->shapes, right_item);

	//left sphere
	t_shape	*left = create_shape(TYPE_SPHERE);

	t_matrix	*left_transl = matrix_create_translate(-1.5, 0.33, -0.75);
	t_matrix	*left_scali = matrix_create_scaling(0.33, 0.33, 0.33);

	matrix_mult(left_transl, left_scali, left->transformation);
	create_inverted(left->transformation, left->transformation_inv);

	destroy_matrix(&left_transl);
	destroy_matrix(&left_scali);

	fill_material(&left->material);
	fill_color(&left->material.color, 1, 0.8, 0.1);
	left->material.diffuse = 0.7;
	left->material.specular = 0.3;

	t_list *left_item = ft_lstnew(left);
	ft_lstadd_back(&w->shapes, left_item);
}

int main(void)
{
	t_world	*w = dcreate_world(1);

	//luz
	t_color color; color.red = 1; color.green = 1; color.blue = 1;
	t_light	*light = create_light(&color, -10, 10, -10);
	t_list  *light_item = ft_lstnew(light);
	w->lights = light_item;

	add_wall_and_floor(w);

	add_sphere(w);

	t_camera *camera = start_camera();
	t_canvas *canvas = create_canvas(WIDHT, HEIGHT, FALSE);


	//process the raytracing
	render(camera, w, canvas);
	save_ppm(canvas);


	//destroy all things
	destroy_world(&w);
	destroy_camera(&camera);
	destroy_canvas(&canvas);

	return 0;
}