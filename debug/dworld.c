#include "dworld.h"

#include "world.h"
#include "shape.h"
#include "matrix_fill.h"
#include "libft.h"
#include "light.h"
#include "matrix_fill.h"

t_world	*dcreate_world()
{
	t_world *world = ft_calloc(1, sizeof(*world));

	t_shape *s1 = create_shape(TYPE_SPHERE);
	fill_material(&s1->material);
	t_shape *s2 = create_shape(TYPE_SPHERE);
	fill_material(&s2->material);

	t_color light_color; light_color.red = 1; light_color.green = 1; light_color.blue = 1;
	t_light *light = create_light(&light_color, -10, 10, -10);

	t_list *itemShape1 = ft_lstnew(NULL);
	t_list *itemShape2 = ft_lstnew(NULL);

	t_list *itemLight = ft_lstnew(NULL);

	if (!s1 || !s2 || !world || !light || !itemShape1 || !itemShape2)
	{
		destroy_shape(&s1);
		destroy_shape(&s2);
		if (world)
			free(world);
		destroy_light(&light);
		if (itemShape1)
			free(itemShape1);
		if (itemShape2)
			free(itemShape2);
		return (NULL);
	}

	//s1
	fill_color(&s1->material.color, 0.8, 1.0, 0.6);
	s1->material.diffuse = 0.7;
	s1->material.specular = 0.2;

	//s2
	matrix_fill_scaling(s2->transformation, 0.5, 0.5, 0.5);

	//the list
	itemShape1->content = s1;
	itemShape2->content = s2;
	itemShape1->next = itemShape2;

	itemLight->content = light;

	world->shapes = itemShape1;
	world->lights = itemLight;

	return (world);
}

