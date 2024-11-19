/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation_convert.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 08:57:13 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/23 11:48:19 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_ROTATION_CONVERT_H
# define MATRIX_ROTATION_CONVERT_H
# include "transformation.h"

void	tokens_to_rotation(t_transformation *tt, double xyz_double[3]);

#endif