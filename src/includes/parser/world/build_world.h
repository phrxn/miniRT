/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_world.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:09:39 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/23 14:10:08 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_WORLD_H
# define BUILD_WORLD_H

# include "world.h"
# include "libft.h"

# define ERR_MALLOC_WORLD 1
# define ERR_MALLOC_TRANSFOR_MATRIX 2


t_world	*build_a_world(t_list *valid_list_line);

#endif