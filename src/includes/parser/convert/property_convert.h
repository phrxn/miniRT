/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   property_convert.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:37:54 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/22 14:27:17 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROPERTY_CONVERT_H
# define PROPERTY_CONVERT_H
# include "token.h"
# include "libft.h"

int	property_to_int(t_token *token, int *result);
int	property_to_double(t_token *token, double *result);
int	property_xyz_to_double(t_list *token_list, double xyz[3]);
int	property_xyz_to_int(t_list *token_list, int xyz[3]);
int	property_to_number(t_token *token, double *result);
int	property_xyz_to_number(t_list *token_list, double xyz[3]);

#endif
