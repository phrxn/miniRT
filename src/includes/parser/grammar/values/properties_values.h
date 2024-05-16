/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   properties_values.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:14:05 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/22 19:14:28 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROPERTIES_VALUES_H
# define PROPERTIES_VALUES_H

#include "libft.h"

int check_property_values_coor(t_list *token_list);

int check_property_values_direction(t_list *token_list);

int check_property_values_color(t_list *token_list);

int check_property_values_fov(t_list *token_list);

int check_property_values_radio(t_list *token_list);

int check_property_values_diam(t_list *token_list);

int check_property_values_height(t_list *token_list);

int check_property_values_coor_camera(t_list *token_list);

#endif