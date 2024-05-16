#ifndef PRINT_OBJECT_H
#define PRINT_OBJECT_H

#include "matrix.h"
#include "color.h"
#include "camera.h"

void print_matrix(t_matrix *to_print, int detalhed);

void print_color(t_color *color);

void print_camera(t_camera *camera);

#endif