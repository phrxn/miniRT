#ifndef PREPARE_COMPUTATIONS_H
# define PREPARE_COMPUTATIONS_H

# include "shape.h"
# include "matrix.h"
# include "intersect.h"
# include "types.h"

typedef struct  s_prepare_computations
{
    double      t;
    t_shape     *shape;
    t_matrix    *point;
    t_matrix    *eyev;
    t_matrix    *normalv;
	BOOL		inside;
}   t_prepare_computations;

t_prepare_computations	*create_pre_computations(t_inter *inter, t_ray *ray);

void	destroy_pre_computations(t_prepare_computations **pre);

#endif