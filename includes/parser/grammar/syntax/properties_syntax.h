/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   properties_syntax.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:27:19 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/26 03:54:10 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROPERTIES_SYNTAX_H
# define PROPERTIES_SYNTAX_H

# include "libft.h"

int	check_property_syntax_coor(t_list *token_list);

int	check_property_syntax_direction(t_list *token_list);

int	check_property_syntax_color(t_list *token_list);

int	check_property_syntax_fov(t_list *token_list);

int	check_property_syntax_radio(t_list *token_list);

int	check_property_syntax_diam(t_list *token_list);

int	check_property_syntax_height(t_list *token_list);

int	check_property_syntax_identifier(t_list *token_list);

#endif