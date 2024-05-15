/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:26:09 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/15 11:16:40 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"
#include "libft.h"
#include <stdio.h>

t_line	*create_line(t_list *token_list,  t_uint line_number)
{
	t_line	*new_line;

	new_line = ft_calloc(1, sizeof(*new_line));
	if (!new_line)
		return (NULL);
	new_line->token_list = token_list;
	new_line->line_number = line_number;
	return (new_line);
}

void	destroy_line(void *line)
{
	t_line	*line_tmp;

	line_tmp = (void*)line;
	if (!line_tmp)
		return ;
	if (line_tmp->token_list)
		ft_lstclear(&line_tmp->token_list, destroy_token2);
	free(line_tmp);
}