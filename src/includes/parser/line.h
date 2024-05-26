/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:22:21 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/26 04:02:29 by gacalaza         ###   ########.fr       */
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

t_line	*create_line(t_list *token_list, t_uint line_number);

void	destroy_line(void *line);

#endif