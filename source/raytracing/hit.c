/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:44:39 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/01 18:31:48 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"
#include "intersect.h"
#include "libft.h"
#include "types.h"
#include "array.h"

static t_inter	*get_non_negative(t_list *lst, t_uint *count, t_uint size)
{
	t_inter	*inter;
	t_inter	*tmp_inter;
	t_list	*tmp_lst;

	inter = NULL;
	while (*count < size)
	{
		tmp_lst = ft_lstget(lst, *count);
		tmp_inter = (t_inter *)tmp_lst->content;
		if (tmp_inter->t >= 0)
		{
			inter = tmp_inter;
			break ;
		}
		(*count)++;
	}
	return (inter);
}

t_inter	*hit(t_list *lst)
{
	t_inter	*inter;
	t_inter	*tmp_inter;
	t_list	*tmp_lst;
	t_uint	count;
	t_uint	size;

	count = 0;
	size = ft_lstsize(lst);
	inter = get_non_negative(lst, &count, size);
	while (count < size)
	{
		tmp_lst = ft_lstget(lst, count);
		tmp_inter = (t_inter *)tmp_lst->content;
		if (tmp_inter->t > 0 && tmp_inter->t < inter->t)
			inter = tmp_inter;
		count++;
	}
	return (inter);
}
