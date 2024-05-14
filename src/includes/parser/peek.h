/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peek.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:04:02 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/04/30 16:04:02 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEEK_H
# define PEEK_H

typedef enum e_char_type
{
	word = 1,
	number,
	signal_pos,
	signal_neg,
	dot,
	space,
	comma,
	end_line
}	t_char_type;

t_char_type	peek(char character);

#endif