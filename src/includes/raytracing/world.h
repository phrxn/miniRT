/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:32:14 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/04/23 21:50:37 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "matrix.h"
# include "intersect.h"
# include "libft.h"

typedef struct s_world
{
	t_list	*intersections;

}	t_world;

#endif
