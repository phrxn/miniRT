/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 23:13:02 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/04/27 18:25:35 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "array.h"
# include "libft.h"
# include "types.h"

t_list	*ft_lstget(t_list *head, t_uint index)
{
    t_uint	count;

    count = 0;
    while(head && count < index)
	{
        head = head->next;
		count++;
	}
    return head;
}

void	ft_lstsort(t_list *head, void sort_function(void *a, void *b))
{
    t_uint	list_size;
    t_uint	count_i;
    t_uint	count_j;
	t_list  *aux;

    list_size = ft_lstsize(head);
    count_i = 0;
    if (!head || !head->next)
        return ;
    while (count_i <  list_size-1)
    {
        count_j = 0;
        while (count_j <  list_size-count_i-1)
        {
			aux = ft_lstget(head, count_j);
            sort_function(aux->content, aux->next->content);
            count_j++;
        }
        count_i++;
    }
}