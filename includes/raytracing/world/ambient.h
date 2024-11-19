/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:38:06 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/26 04:21:41 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMBIENT_H
# define AMBIENT_H
# include "color.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_ambient
{
	double	radio;
	t_color	color;
}	t_ambient;

t_ambient	*create_ambient(void);

void		destroy_ambient(t_ambient **ambient);

#endif