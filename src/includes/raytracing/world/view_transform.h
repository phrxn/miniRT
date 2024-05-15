/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transform.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 04:10:52 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/15 04:19:16 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_TRANSFORM_H
# define VIEW_TRANSFORM_H

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

t_matrix	*view_transform(t_matrix *from_p, t_matrix *to_p, t_matrix *up_v);

#endif