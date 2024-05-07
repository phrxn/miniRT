/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:50:52 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/06 21:38:59 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reflect.h"
#include "matrix.h"
#include "matrix_alloc.h"
#include "matrix_operations.h"
#include "messages.h"

t_matrix	*reflect(t_matrix *in, t_matrix *normal)
{
	t_matrix	*subt;
	double		dot;
	int			status;

	status = 0;
	subt = matrix_create_vector(normal->elements[X], normal->elements[Y],
			normal->elements[Z]);
	if (!subt)
		return (NULL);
	status = matrix_dot(in, normal, &dot);
	if (status == 0)
		matrix_mult_scalar(subt, dot * 2);
	if (status == 0)
		status = matrix_subtraction(in, subt, subt);
	if (status != OK_OPERATION)
	{
		show_error_method("reflect", MERR_INVALID_DOT);
		destroy_matrix(&subt);
	}
	return (subt);
}
