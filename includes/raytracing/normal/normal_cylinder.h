/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_cylinder.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:59:50 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/19 20:13:13 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMAL_CYLINDER_H
# define NORMAL_CYLINDER_H

# include "matrix.h"
# include "shape.h"

t_matrix	*normal_at_cylinder(t_shape *shape, t_matrix *point);

#endif