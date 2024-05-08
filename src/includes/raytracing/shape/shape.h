/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:41:10 by gacalaza          #+#    #+#             */
/*   Updated: 2024/04/30 19:47:46 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include "matrix.h"
# include "types.h"

# define TYPE_SPHERE	1

# define OK_MALLOC 0
# define ERR_MALLOC_SHAPE 1

# include "canvas.h"
# include "material.h"


typedef struct s_shape
{
	int			type;
	void		*shape;
	t_uint		id;
	t_matrix	*transformation;
	t_material	material;
}	t_shape;

typedef struct s_sphere
{
	t_matrix	*center;
	double		radius;
}	t_sphere;

int		create_shape(t_shape **shape);
void	destroy_shape(t_shape **shape);

//sphere
t_shape	*create_sphere(t_uint id);
void	destroy_sphere(t_shape **shape);

#endif
