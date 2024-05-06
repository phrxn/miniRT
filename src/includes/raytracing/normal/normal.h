/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:33:40 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/04 21:02:41 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMAL_H
# define NORMAL_H

# include "matrix.h"
# include "shape.h"

# define MERR_INVALID_OBJ_TYPE		"The shape type doesn't exist"
# define MERR_MATRIX_NORMALIZATION	"Matrix normalization not possible"

typedef struct s_normal
{
	t_matrix	*inv;
	t_matrix	*local_point;
	t_matrix	*local_nml;
	t_matrix	*world_normal;
	int			status;
}	t_normal;

t_matrix	*normal_at(t_shape *shape, t_matrix *point);

#endif