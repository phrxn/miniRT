/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:15:41 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/23 11:39:21 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORMATION_H
# define TRANSFORMATION_H

# include "matrix.h"

typedef struct s_transformation
{
	t_matrix	*translation;
	t_matrix	*rotation;
	t_matrix	*scale;
	t_matrix	*transformation;
	t_matrix	*transformation_inv;
	t_matrix	*tmp;
}	t_transformation;

t_transformation	*create_transformation();

void				destroy_transformation(t_transformation	**transf);

void				fill_transformation_identity(t_transformation *transf);

int					make_transformation(t_transformation *transf);

#endif