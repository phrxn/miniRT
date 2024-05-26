/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peek.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:26:17 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/06 14:26:17 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "peek.h"

t_char_type	peek(char character)
{
	if (character >= '0' && character <= '9')
		return (number);
	if (character == '+')
		return (signal_pos);
	if (character == '-')
		return (signal_neg);
	if (character == '.')
		return (dot);
	if (character == ',')
		return (comma);
	if (character == ' ' || character == '\t')
		return (space);
	if (character == '\0')
		return (end_line);
	return (word);
}
