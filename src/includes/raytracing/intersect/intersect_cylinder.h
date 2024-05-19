/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:18:15 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/19 19:47:20 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_CYLINDER_H
# define INTERSECT_CYLINDER_H
# include "ray.h"
# include "shape.h"
# include "libft.h"

# define	A 0
# define	B 1
# define	C 2

# define MERR_ALLOC_INTER "while allocating intersection"
# define MERR_CREATING_LST "while creating list"

typedef struct s_inter_cy_vars
{
	double		abc[3];
	double		disc;
	double		t0;
	double		t1;
	double		y0;
	double		y1;
	int			status;
	t_list		*inter_list;
	t_cylinder	*cy;

}		t_inter_cy_vars;

t_list	*intersect_cylinder(t_shape *shape, t_ray *ray_transformed);
char	check_cap_cylinder(t_ray *ray, double t);

#endif