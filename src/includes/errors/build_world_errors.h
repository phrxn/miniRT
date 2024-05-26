/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_world_errors.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:09:15 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/26 03:50:34 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_WORLD_ERRORS_H
# define BUILD_WORLD_ERRORS_H

# include "line.h"

void	show_error_build_world(int error_code);
void	show_error_build_element(int error_code, t_line *line);

#endif