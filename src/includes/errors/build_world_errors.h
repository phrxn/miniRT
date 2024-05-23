/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_world_errors.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:09:15 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/23 21:01:29 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_WORLD_ERRORS_H
# define BUILD_WORLD_ERRORS_H

# include "line.h"

void	show_error_build_world(int error_code);

void 	show_error_build_element(int error_code, t_line *line);

#endif