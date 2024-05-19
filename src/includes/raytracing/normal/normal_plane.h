/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_plane.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 01:20:23 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/19 01:21:24 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMAL_PLANE_H
# define NORMAL_PLANE_H

# include "matrix.h"
# include "shape.h"

t_matrix	*normal_at_plane(t_shape *shape, t_matrix *point);

#endif