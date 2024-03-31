/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 19:13:30 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/03/30 21:51:14 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H
# include <stdlib.h>

void *malloc_mock_matrix(size_t size);

# define malloc malloc_mock

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