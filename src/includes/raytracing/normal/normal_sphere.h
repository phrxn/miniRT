/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_sphere.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:34:43 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/04 17:40:21 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMAL_SPHERE_H
# define NORMAL_SPHERE_H

# include "matrix.h"
# include "shape.h"

t_matrix	*normal_at_sphere(t_shape *shape, t_matrix *point);

#endif