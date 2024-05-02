/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:19:18 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/01 20:07:37 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect_utils.h"
#include "intersect.h"

void	sort_intersection(t_inter **t1, t_inter **t2)
{
	double	value1;
	double	value2;
	t_inter	*temp;

	value1 = (*t1)->t;
	value2 = (*t2)->t;
	if (value2 < value1)
	{
		temp = *t1;
		*t1 = *t2;
		*t2 = temp;
	}
}

t_inter	*create_intersection(double t, t_shape *shape)
{
	t_inter	*new_inter;

	new_inter = malloc(sizeof(*new_inter) * 1);
	if (!new_inter)
		return (NULL);
	new_inter->t = t;
	new_inter->shape = shape;
	return (new_inter);
}

void	destroy_intersection(t_inter	**intersec)
{
	if (!intersec || !*intersec)
		return ;
	free(*intersec);
	*intersec = NULL;
}

void	destroy_intersection2(void	*del)
{
	t_inter	*intersec;

	intersec = (t_inter *)del;
	if (!intersec)
		return ;
	free(intersec);
}
