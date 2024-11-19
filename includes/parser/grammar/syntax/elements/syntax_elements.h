/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_elements.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:48:47 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/26 03:54:20 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_ELEMENTS_H
# define SYNTAX_ELEMENTS_H

# include "libft.h"

int	syntax_ambient(t_list *token_list);
int	syntax_camera(t_list *token_list);
int	syntax_cylinder(t_list *token_list);
int	syntax_light(t_list *token_list);
int	syntax_plane(t_list *token_list);
int	syntax_sphere(t_list *token_list);

#endif