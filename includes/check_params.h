/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:36:15 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/04/13 19:11:38 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_PARAMS_H
# define CHECK_PARAMS_H

# define MSG_INV_PARAMS "Invalid number of parameters"
# define MSG_INV_EXTENSION "Invalid file extension, must be \".rt\""

void	check_params(int argc, char *argv[]);

#endif