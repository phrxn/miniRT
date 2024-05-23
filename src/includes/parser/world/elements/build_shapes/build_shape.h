/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_shape.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 21:10:20 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/24 22:22:09 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_SHAPE_H
# define BUILD_SHAPE_H

# include "world.h"
# include "libft.h"
# include "transformation.h"

int	build_shape_cylinder(t_world *wrl, t_list *token_list, t_transformation *t);

int	build_shape_plane(t_world *wrl, t_list *token_list, t_transformation *t);

int	build_shape_sphere(t_world *wrl, t_list *token_list, t_transformation *t);

#endif