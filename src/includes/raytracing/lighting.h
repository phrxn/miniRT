/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:56:26 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/18 20:32:37 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTING_H
# define LIGHTING_H

# include "matrix.h"
# include "world.h"
# include "shape.h"
# include "color.h"
# include "light.h"

# define MERR_MALLOC_LIGHTV "Error while allocing light vector"
# define MERR_MALLOC_REFLEC "Error while allocing reflect vector"

typedef struct s_lighting_params
{
	t_material	*material;
	t_light		*light;
	t_matrix	*point;
	t_matrix	*eyev;
	t_matrix	*normalv;
	char		in_shadow;

}			t_lighting_params;

typedef struct s_lighting_vars
{
	t_color		diffuse;
	t_color		specular;
	t_color		ambient;
	t_color		effective_color;
	t_color		return_color;
	t_matrix	*lightv;
	t_matrix	*reflectv;
	double		light_dot_normal;
	double		reflect_dot_eye;
	double		factor;

}			t_lighting_vars;

t_color	lighting(t_lighting_params *params);

#endif