/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:32:51 by gacalaza          #+#    #+#             */
/*   Updated: 2024/04/23 20:21:53 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include "matrix.h"

typedef struct s_ray
{
	t_matrix	*origin;
	t_matrix	*direction;
}			t_ray;

t_matrix	*position(t_ray *ray, double t);
t_ray		*create_ray(t_matrix *origin, t_matrix *direction);
void		destroy_ray(t_ray **ray);

#endif
