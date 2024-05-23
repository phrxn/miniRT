/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_elements.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:12:52 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/23 22:43:56 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	COUNT_ELEMENTS_H
# define COUNT_ELEMENTS_H

# define OK_ELEMENT_NUMBERS 0
# define ERR_ELEMENT_NUMBERS 1

# define ERR_NUMBER_OF_CAMERAS 2
# define ERR_NUMBER_OF_LIGHT 3
# define ERR_NUMBER_OF_AMBIENT 4

# include "libft.h"
# include "types.h"

typedef struct s_count_elements
{
	t_uint	ambient_quantity;
	t_uint	camera_quantity;
	t_uint	light_quantity;
}	t_count_elements;

int	count_elements(t_list *valid_line_list);

#endif