/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 01:27:42 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/15 03:15:10 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "matrix.h"

typedef struct	s_view_transf_vars
{
	t_matrix	*forward;
	t_matrix	*upn;
	t_matrix	*left;
	t_matrix	*true_up;
	t_matrix	*orientation;
	t_matrix	*translation;
}	t_view_transf_vars;

t_matrix	*view_transform(t_matrix *from, t_matrix *to, t_matrix *up);

#endif