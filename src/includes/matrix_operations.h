/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:35:20 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/04/11 22:50:46 by dmanoel-         ###   ########.fr       */
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

# define POINT						1
# define VECTOR						0

# define X							0
# define Y							1
# define Z							2
# define W							3

double	matrix_get_magnitude(t_matrix *a);
int		matrix_normalization(t_matrix *a, t_matrix *unit);
int		matrix_dot(t_matrix *a, t_matrix *b, double *c);
int		matrix_cross(t_matrix *a, t_matrix *b, t_matrix *c);
int		matrix_addition(t_matrix *a, t_matrix *b, t_matrix *c);
int		matrix_subtration(t_matrix *a, t_matrix *b, t_matrix *c);
void	matrix_negation(t_matrix *a);
void	matrix_mult_scalar(t_matrix *a, double scalar);
void	matrix_div_scalar(t_matrix *a, double scalar);
int		matrix_mult(t_matrix *a, t_matrix *b, t_matrix *c);
void	matrix_transpose(t_matrix *a, t_matrix *b);
int		matrix_determinant_4x4(t_matrix *matrix_4x4, t_matrix *result);
double	cofactor_3x3(t_matrix *matrix_4x4, int row, int col);
int		matrix_inverse_4x4(t_matrix *matrix_4x4, t_matrix *result);

#endif
