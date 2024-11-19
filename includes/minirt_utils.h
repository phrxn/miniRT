/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:58:06 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/25 19:25:27 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_UTILS_H
# define MINIRT_UTILS_H

# include "minirt.h"

# define OK_START 0
# define ERR_START 1

void	start_minirt(t_minirt *minirt);

void	destroy_minirt(t_minirt *minirt);

#endif