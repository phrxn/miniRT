#ifndef COMPARE_H
#define COMPARE_H

#include "../src/includes/matrix.h"

#define EPSILON 0.00001

int compare_double(double a, double b);

int	compare_matrix(t_matrix *a, t_matrix *b);

#endif