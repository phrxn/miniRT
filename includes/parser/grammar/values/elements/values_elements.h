/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_elements.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:19:39 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/26 03:55:10 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALUES_ELEMENTS_H
# define VALUES_ELEMENTS_H

# include "libft.h"

int	values_ambient(t_list *token_list);
int	values_camera(t_list *token_list);
int	values_cylinder(t_list *token_list);
int	values_light(t_list *token_list);
int	values_plane(t_list *token_list);
int	values_sphere(t_list *token_list);

#endif