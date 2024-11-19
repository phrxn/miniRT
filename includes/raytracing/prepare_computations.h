/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_computations.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 04:10:39 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/26 04:21:41 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PREPARE_COMPUTATIONS_H
# define PREPARE_COMPUTATIONS_H

# include "shape.h"
# include "matrix.h"
# include "intersect.h"
# include "types.h"

typedef struct s_prepare_computations
{
	double		t;
	t_shape		*shape;
	t_matrix	*point;
	t_matrix	*eyev;
	t_matrix	*normalv;
	t_matrix	*over_point;
	char		inside;
}	t_prepare_computations;

t_prepare_computations	*create_pre_computations(t_inter *inter, t_ray *ray);

void					destroy_pre_computations(t_prepare_computations **pre);

#endif