/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transform.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 04:10:52 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/26 04:21:41 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_TRANSFORM_H
# define VIEW_TRANSFORM_H

# include "matrix.h"

typedef struct s_view_transf_vars
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