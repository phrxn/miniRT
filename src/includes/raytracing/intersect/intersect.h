/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:14:20 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/06 20:28:14 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_H
# define INTERSECT_H

# include "shape.h"
# include "libft.h"
# include "ray.h"

# define MERR_INVALID_OBJ_TYPE	"The shape type doesn't exist"

typedef struct s_inter
{
	double	t;
	t_shape	*shape;
}			t_inter;

t_list	*intersect(t_shape *shape, t_ray *ray_transformed);

#endif
