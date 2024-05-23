/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_element.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:20:14 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/24 19:55:28 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_ELEMENT_H
# define SELECT_ELEMENT_H

# include "token.h"

typedef enum	e_element_type
{
	not_exist = 1,
	ambient,
	camera,
	light,
	sphere,
	plane,
	cylinder
}	t_element_type;

t_element_type	select_element_type(t_token *token_identifier);

t_element_type	get_element_type(t_list *token_list);

#endif