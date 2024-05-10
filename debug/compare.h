#ifndef COMPARE_H
#define COMPARE_H

#include "matrix.h"
#include "color.h"
#include "shape.h"
#include "material.h"

#define EPSILON 0.00001

int compare_double(double a, double b);

int	compare_matrix(t_matrix *a, t_matrix *b);

int	compare_color(t_color *a, t_color *b);

int compare_material(t_material *a, t_material *b);

int	compare_shape(t_shape *a, t_shape *b);

int compare_sphere(t_sphere *a, t_sphere *b);

#endif