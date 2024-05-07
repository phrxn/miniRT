/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:50:38 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/06 21:05:25 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REFLECT_H
# define REFLECT_H

# include "matrix.h"

# define MERR_INVALID_DOT "Invalid dot product"

t_matrix	*reflect(t_matrix *in, t_matrix *normal);

#endif
