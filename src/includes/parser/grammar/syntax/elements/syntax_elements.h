/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_elements.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:48:47 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/20 14:20:23 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_ELEMENTS_H
# define SYNTAX_ELEMENTS_H

#include "libft.h"

int	syntax_ambient(t_list *token_list);
int	syntax_camera(t_list *token_list);
int	syntax_cylinder(t_list *token_list);
int	syntax_light(t_list *token_list);
int	syntax_plane(t_list *token_list);
int	syntax_sphere(t_list *token_list);

#endif