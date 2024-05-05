/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:59:33 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/04 21:55:13 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_errors.h"
#include "matrix.h"
#include "matrix_operations.h"
#include "messages.h"

void	show_error_matrix(char *method, int code_error)
{
	if (code_error == ERR_ROWS_SIZE)
		return (show_error_method(method, MERR_ROWS_SIZE));
	if (code_error == ERR_COLS_SIZE)
		return (show_error_method(method, MERR_COLS_SIZE));
	if (code_error == ERR_NOT_VECTOR)
		return (show_error_method(method, MERR_NOT_VECTOR));
	if (code_error == ERR_MAGNITUDE_ZERO)
		return (show_error_method(method, MERR_MAGNITUDE_ZERO));
	if (code_error == ERR_MATRIX_MUL_ROW_COL)
		return (show_error_method(method, MERR_MATRIX_MUL_ROW_COL));
	if (code_error == ERR_MATRIX_MUL_INV_RESULT)
		return (show_error_method(method, MERR_MATRIX_MUL_INV_RESULT));
	if (code_error == ERR_DETERMINANT_ZERO)
		return (show_error_method(method, MERR_DETERMINANT_ZERO));
}
