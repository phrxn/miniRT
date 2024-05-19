/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:50:52 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/19 18:42:42 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H
# include <math.h>

# define TRUE 1
# define FALSE 0

# define EPSILON 0.00001

static inline int	equals_double(double a, double b)
{
	return (fabs(a - b) > EPSILON);
}

static inline int	nearly_zero(double a)
{
	return (fabs(a) < EPSILON);
}

typedef unsigned int	t_uint;

#endif
