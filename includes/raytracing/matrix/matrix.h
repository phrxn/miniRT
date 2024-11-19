/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 19:13:30 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/04/20 19:12:28 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H
# include <stdlib.h>

# define MATRIX_4X4_SIZE 16

# define POINT						1
# define VECTOR						0

# define X							0
# define Y							1
# define Z							2
# define W							3

typedef struct s_matrix
{
	int		rows;
	int		cols;
	double	*elements;
}	t_matrix;

double		get_element(t_matrix *matrix, int row, int col);

void		set_element(t_matrix *matrix, int row, int col, double value);

t_matrix	*create_matrix(int rows, int cols);

void		destroy_matrix(t_matrix **matrix);

#endif