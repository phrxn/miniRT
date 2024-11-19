/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:06:54 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/06 15:06:54 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "libft.h"
# include "types.h"

# ifdef TEST
#  define STATIC
# else
#  define STATIC static
# endif

typedef struct s_stream
{
	const char	*line;
	t_uint		index;
}	t_stream;

# ifdef TEST

char	*prepared_line(const char *line_readed);
# endif

t_list	*line_create_tokens(const char *line_to_split);
t_list	*create_line_list(int fd);
void	destroy_line_list(t_list **line_list);

#endif