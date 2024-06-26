/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commons_build.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 02:34:16 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/26 03:58:57 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMONS_BUILD_H
# define COMMONS_BUILD_H

# include "transformation.h"
# include "shape.h"

int	start_shape(t_shape *shape, t_transformation *transf, double color[3]);

#endif