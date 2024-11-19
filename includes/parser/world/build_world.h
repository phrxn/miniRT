/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_world.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:09:39 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/24 23:58:36 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_WORLD_H
# define BUILD_WORLD_H

# include "world.h"
# include "libft.h"

# define OK_BUILD_ELEMENT 0
# define ERR_MALLOC_WORLD 1
# define ERR_MALLOC_TRANSFOR_MATRIX 2

# define ERR_BUILD_ELEMENT_NOT_EXIT 3
# define ERR_BUILD_CONVERT_TOKENS 4
# define ERR_BUILD_ELEMENT_MALLOC 5
# define ERR_BUILD_ELEMENT_INV_MATRIX 6
# define ERR_BUILD_ELEMENT_MAKE_TRANSF_MATRIX 7

t_world	*build_a_world(t_list *valid_list_line);

#endif