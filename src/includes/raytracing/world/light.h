#ifndef LIGHT_H
# define LIGHT_H

# include "color.h"
# include "matrix.h"

typedef struct s_light
{
	t_color		intensity;
	t_matrix	*position;
}	t_light;


t_light	*create_light(t_color *color, double x, double y, double z);

void	destroy_light(t_light **light);

#endif