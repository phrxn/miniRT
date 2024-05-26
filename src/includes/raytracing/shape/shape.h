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
# define TYPE_PLANE		2
# define TYPE_CYLINDER  3

# include "material.h"

typedef struct s_shape
{
	int			type;
	void		*shape;
	t_uint		id;
	t_matrix	*transformation;
	t_matrix	*transformation_inv;
	t_material	material;
}	t_shape;

typedef struct s_sphere
{
	t_matrix	*center;
	double		radius;
}	t_sphere;

typedef struct s_cylinder
{
	char	is_closed;
	double	minimum;
	double	maximum;
}	t_cylinder;

//the shapes
t_shape		*create_shape(int type);
void		destroy_shape(t_shape **shape);
void		destroy_shape2(void *shape);
t_shape		*create_shape_copy(t_shape	*shape);

//sphere
t_sphere	*create_sphere(void);
void		destroy_sphere(t_sphere **sphere);
void		copy_sphere(t_sphere *from, t_sphere *to);

//cylinder
t_cylinder	*create_cylinder(void);
void		destroy_cylinder(t_cylinder **cylinder);
void		copy_cylinder(t_cylinder *from, t_cylinder *to);

#endif