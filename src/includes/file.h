/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:26:41 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/04/22 19:10:50 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H
# include "minirt.h"

# define MSG_OPEN_RT_FILE "Could not open the rt file"

int	open_file(char *file_name, t_minirt *minirt);

#endif