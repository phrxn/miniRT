#ifndef COMPARE_H
#define COMPARE_H

#include "matrix.h"
#include "color.h"

#define EPSILON 0.00001

int compare_double(double a, double b);

int	compare_matrix(t_matrix *a, t_matrix *b);

int	compare_color(t_color *a, t_color *b);

#endif