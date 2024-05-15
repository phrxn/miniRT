/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 04:10:28 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/15 04:20:09 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "view_transform.h"
#include "matrix.h"
#include "matrix_alloc.h"
#include "matrix_operations.h"
#include "libft.h"

static void end_vars(t_view_transf_vars *vars)
{
		destroy_matrix(&vars->forward);
		destroy_matrix(&vars->upn);
		destroy_matrix(&vars->left);
		destroy_matrix(&vars->true_up);
		destroy_matrix(&vars->orientation);
		destroy_matrix(&vars->translation);
}

static int start_vars(t_view_transf_vars *vars, t_matrix *from, t_matrix *to)
{

	vars->forward =	matrix_create_subtraction(to, from);
	vars->upn = matrix_create_vector(0,0,0);
	vars->left = matrix_create_point(0,0,0);
	vars->true_up = matrix_create_point(0,0,0);
	vars->orientation = matrix_create_identity_4x4();
	vars->translation = matrix_create_identity_4x4();
	if (!vars->forward || !vars->upn || !vars->left || !vars->true_up
		|| !vars->orientation || !vars->translation)
	{
		end_vars(vars);
		return (1);
	}
	return (0);
}

t_matrix	*view_transform(t_matrix *from_p, t_matrix *to_p, t_matrix *up_v)
{
	t_view_transf_vars	vars;
	t_matrix			*view_matrix;

	if (start_vars(&vars, from_p, to_p))
		return (NULL);
	matrix_normalization(vars.forward, vars.forward);
	matrix_normalization(up_v, vars.upn);
	matrix_cross(vars.forward, vars.upn, vars.left);
	matrix_cross(vars.left, vars.forward, vars.true_up);
	set_element(vars.orientation, 0, 0, vars.left->elements[X]);
	set_element(vars.orientation, 0, 1, vars.left->elements[Y]);
	set_element(vars.orientation, 0, 2, vars.left->elements[Z]);
	set_element(vars.orientation, 1, 0, vars.true_up->elements[X]);
	set_element(vars.orientation, 1, 1, vars.true_up->elements[Y]);
	set_element(vars.orientation, 1, 2, vars.true_up->elements[Z]);
	set_element(vars.orientation, 2, 0, -vars.forward->elements[X]);
	set_element(vars.orientation, 2, 1, -vars.forward->elements[Y]);
	set_element(vars.orientation, 2, 2, -vars.forward->elements[Z]);
	matrix_fill_translation(vars.translation, -from_p->elements[X],
		-from_p->elements[Y],
		-from_p->elements[Z]);
	view_matrix = matrix_create_mult(vars.orientation, vars.translation);
	end_vars(&vars);
	return (view_matrix);
}
