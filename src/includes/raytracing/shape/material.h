#ifndef MATERIAL_H
# define MATERIAL_H

# include "color.h"

typedef struct s_material
{
	t_color	color;
	double	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
}	t_material;

void    fill_material(t_material *material);

#endif