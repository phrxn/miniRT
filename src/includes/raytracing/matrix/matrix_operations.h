/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:35:20 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/04 22:02:16 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_OPERATIONS_H
# define MATRIX_OPERATIONS_H

# include "matrix.h"

# define OK_OPERATION				0

# define ERR_ROWS_SIZE				1
# define ERR_COLS_SIZE				2
# define ERR_NOT_VECTOR				3
# define ERR_MAGNITUDE_ZERO			4
# define ERR_MATRIX_MUL_ROW_COL		5
# define ERR_MATRIX_MUL_INV_RESULT	6
# define ERR_DETERMINANT_ZERO 		7
# define ERR_MATRIX_TRANSP_ROW		8
# define ERR_MATRIX_TRANSP_COL		9

# define MERR_ROWS_SIZE				"The number of rows is different in both \
matrices."
# define MERR_COLS_SIZE				"The number of columns is different in \
both matrices."
# define MERR_NOT_VECTOR			"The matrix isn't a vector."
# define MERR_MAGNITUDE_ZERO		"The vector magnitude is zero."
# define MERR_MATRIX_MUL_ROW_COL	"The number of columns in A matrix is \
different from matrix B."
# define MERR_MATRIX_MUL_INV_RESULT	"The number of rows in result matrix is \
different from matrix A or the number of columns in result matrix \
is different from matrix B."
# define MERR_DETERMINANT_ZERO 		"Can't inverse matrix, the determinant \
is zero."

double	matrix_get_magnitude(t_matrix *a);
int		matrix_normalization(t_matrix *a, t_matrix *unit);
int		matrix_dot(t_matrix *a, t_matrix *b, double *c);
int		matrix_cross(t_matrix *a, t_matrix *b, t_matrix *c);
int		matrix_addition(t_matrix *a, t_matrix *b, t_matrix *c);
int		matrix_subtraction(t_matrix *a, t_matrix *b, t_matrix *c);
void	matrix_negation(t_matrix *a);
void	matrix_mult_scalar(t_matrix *a, double scalar);
void	matrix_div_scalar(t_matrix *a, double scalar);
int		matrix_mult(t_matrix *a, t_matrix *b, t_matrix *c);
int		matrix_transpose(t_matrix *a, t_matrix *b);
int		matrix_determinant_4x4(t_matrix *matrix_4x4, t_matrix *result);
double	cofactor_3x3(t_matrix *matrix_4x4, int row, int col);
int		matrix_inverse_4x4(t_matrix *matrix_4x4, t_matrix *result);

#endif
