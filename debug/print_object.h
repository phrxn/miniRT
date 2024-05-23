#ifndef PRINT_OBJECT_H
#define PRINT_OBJECT_H

#include "matrix.h"
#include "color.h"
#include "camera.h"
#include "libft.h"
#include "world.h"

void print_matrix(t_matrix *to_print, int detalhed);

void print_color(t_color *color);

void print_camera(t_camera *camera);

void print_line_list(t_list *line_list);

void print_token_list(t_list *list, int print_new_line);

void print_world(const t_world *world);

#endif