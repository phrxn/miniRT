#ifndef SHADE_HIT
#define SHADE_HIT

#include "color.h"
#include "world.h"
#include "prepare_computations.h"
#include "types.h"
#include "light.h"

typedef struct	s_shade_vars
{
	t_color	color_tmp;
	t_color	color;
	t_uint	lst_light_size;
	t_uint	count;
	BOOL	is_shaded;
	t_light	*light;
}	t_shade_vars;

t_color	shade_hit(t_world *world, t_prepare_computations *pre);

#endif