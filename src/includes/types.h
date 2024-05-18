/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:50:52 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/18 15:58:33 by dmanoel-         ###   ########.fr       */
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

typedef unsigned int	t_uint;

#endif
