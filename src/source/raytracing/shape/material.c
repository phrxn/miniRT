#include "material.h"
#include "color.h"

void    fill_material(t_material *material)
{
    fill_color(&material->color, 1,1,1);
    material->ambient = 0.1;
    material->diffuse = 0.9;
    material->specular = 0.9;
    material->shininess = 200;
}