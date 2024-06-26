/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:20:03 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/18 16:30:26 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

# include "matrix.h"
# include "ray.h"
# include "shape.h"

# define MERR_MALLOC_NEW_RAY	"Error when allocating new_ray"
# define MERR_MULT_ORIGIN		"Error when multipling matrix * ray->origin"
# define MERR_MULT_DIRECTION	"Error when multipling matrix * ray->direction"
# define MERR_CREATE_RAY_TRANS "Error when creating the transformed ray"

t_ray	*transform(t_ray *ray, t_matrix *matrix);

t_ray	*transform_ray(t_shape *shape, t_ray *ray);

#endif
