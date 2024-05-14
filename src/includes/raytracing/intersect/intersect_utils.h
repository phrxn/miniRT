/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:19:35 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/12 03:32:34 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_UTILS_H
# define INTERSECT_UTILS_H

# include "intersect.h"

t_inter	*create_intersection(double t, t_shape *shape);
void	sort_intersection(void **t1, void **t2);
void	destroy_intersection(t_inter	**intersec);
void	destroy_intersection2(void	*del);

#endif