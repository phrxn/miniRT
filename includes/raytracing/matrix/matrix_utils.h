/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:54:55 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/09 21:37:36 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_UTILS_H
# define MATRIX_UTILS_H
# include "matrix.h"

void		matrix_copy(t_matrix *from, t_matrix *to);

t_matrix	*matrix_copy_create(t_matrix *to_copy);

#endif