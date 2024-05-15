/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:22:21 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/15 11:17:10 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include "token.h"
# include "types.h"

typedef struct s_line
{
	t_list	*token_list;
	t_uint	line_number;
}	t_line;

t_line	*create_line(t_list *token_list,  t_uint line_number);

void	destroy_line(void *line);

#endif