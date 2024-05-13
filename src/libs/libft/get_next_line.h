/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:32:23 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/13 14:29:47 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_module
{
	char	*buf;
	int		l_start;
	int		l_end;
	int		l_size;
	int		readed;
}	t_module;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);

#endif
