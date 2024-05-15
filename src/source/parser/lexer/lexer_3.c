/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:55:08 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/15 11:13:31 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "line.h"
#include "libft.h"
#include <stdlib.h>

void	destroy_line_list(t_list **line_list)
{
	t_list	*line_list_tmp;

	if (!line_list || !*line_list)
		return ;
	line_list_tmp = *line_list;
	ft_lstclear(&line_list_tmp, destroy_line);
	*line_list = NULL;
}
