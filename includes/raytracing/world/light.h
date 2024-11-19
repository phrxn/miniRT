/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:37:31 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/18 20:37:58 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "color.h"
# include "matrix.h"

typedef struct s_light
{
	t_color		intensity;
	t_matrix	*position;
}	t_light;

t_light	*create_light(t_color *color, double x, double y, double z);
void	destroy_light(t_light **light);
void	destroy_light2(void *del);

#endif