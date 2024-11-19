/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:05:27 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/22 17:40:40 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "line.h"
#include "libft.h"
#include "types.h"
#include <stdlib.h>

/**
 * prepared_line - prepare line to tokenizer
 * @line_readed: line to prepare
 *
 * 1) Remove initial and final spaces
 * 2) change \n to \0 (if exist) in the line
 *
 * Return:
 * 	On failure:
 * 		return NULL (if the line is empty or totally filled with spaces)
 *  On successful:
 * 		a malloced line with \n and "trimed"
*/
STATIC char	*prepared_line(const char *line_readed)
{
	char	*line_prepared;
	char	*line_readed_cpy;
	size_t	line_size;

	if (!line_readed)
		return (NULL);
	line_size = ft_strlen(line_readed);
	if (line_size == 0)
		return (NULL);
	line_readed_cpy = ft_strdup(line_readed);
	if (!line_readed_cpy)
		return (NULL);
	if (line_readed_cpy[line_size - 1] == '\n')
		line_readed_cpy[line_size - 1] = '\0';
	line_prepared = ft_strtrim(line_readed_cpy, " ");
	free(line_readed_cpy);
	if (line_prepared[0] == '\0')
	{
		free(line_prepared);
		return (NULL);
	}
	return (line_prepared);
}

static t_list	*alloc_line_item(t_line *line)
{
	t_list	*new_line_item;

	new_line_item = ft_lstnew(line);
	if (!new_line_item)
		return (NULL);
	new_line_item->content = line;
	return (new_line_item);
}

static t_list	*make_line_item(char *line_prepared, t_uint numb)
{
	t_line	*line;
	t_list	*line_tokens_list;
	t_list	*line_item;

	line_tokens_list = line_create_tokens(line_prepared);
	if (!line_tokens_list)
		return (NULL);
	line = create_line(line_tokens_list, numb);
	if (!line)
	{
		ft_lstclear(&line_tokens_list, destroy_token2);
		return (NULL);
	}
	line_item = alloc_line_item(line);
	if (!line_item)
	{
		destroy_line(line);
		return (NULL);
	}
	return (line_item);
}

/**
 *
*/
static int	add_line_to_list(t_list **line_list, char *line_prep, t_uint numb)
{
	t_list	*line_item;

	line_item = make_line_item(line_prep, numb);
	if (!line_item)
	{
		destroy_line_list(line_list);
		return (1);
	}
	ft_lstadd_back(line_list, line_item);
	return (0);
}

/**
 * creat_line_list - create a list of lines
 *
 * @fd:	the open and valid fd
 *
 * Return:
 * 	On successful:
 * 		the list of lines
 *  On failure:
 * 		NULL is retorned (malloc)
*/
t_list	*create_line_list(int fd)
{
	t_list	*line_list;
	char	*line_readed;
	char	*line_prepared;
	t_uint	count_line;

	line_list = NULL;
	line_prepared = NULL;
	count_line = 0;
	while (1)
	{
		count_line++;
		if (line_prepared)
			free(line_prepared);
		line_readed = get_next_line(fd);
		if (!line_readed)
			break ;
		line_prepared = prepared_line(line_readed);
		free(line_readed);
		if (!line_prepared)
			continue ;
		if (add_line_to_list(&line_list, line_prepared, count_line))
			break ;
	}
	return (line_list);
}
