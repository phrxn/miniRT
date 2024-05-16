#ifndef PRINT_OBJECT_H
#define PRINT_OBJECT_H

#include "matrix.h"
#include "color.h"
#include "libft.h"

void print_matrix(t_matrix *to_print, int detalhed);

void print_color(t_color *color);

void print_line_list(t_list *line_list);

void print_token_list(t_list *list, int print_new_line);

#endif