/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:59:33 by gacalaza          #+#    #+#             */
/*   Updated: 2024/04/22 13:39:15 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_errors.h"
#include "matrix.h"
#include "matrix_operations.h"
#include "messages.h"

void	show_error_matrix(char *method, int code_error)
{
	if (ERR_ROWS_SIZE)
		return (show_error_method(method, MERR_ROWS_SIZE));
	if (ERR_COLS_SIZE)
		return (show_error_method(method, MERR_COLS_SIZE));
	if (ERR_NOT_VECTOR)
		return (show_error_method(method, MERR_NOT_VECTOR));
	if (ERR_MAGNITUDE_ZERO)
		return (show_error_method(method, MERR_MAGNITUDE_ZERO));
	if (ERR_MATRIX_MUL_ROW_COL)
		return (show_error_method(method, MERR_MATRIX_MUL_ROW_COL));
	if (ERR_MATRIX_MUL_INV_RESULT)
		return (show_error_method(method, MERR_MATRIX_MUL_INV_RESULT));
	if (ERR_DETERMINANT_ZERO)
		return (show_error_method(method, MERR_DETERMINANT_ZERO));
}
