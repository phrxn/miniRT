/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_window.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 22:00:04 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/19 22:00:05 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EVENT_WINDOW_H
# define EVENT_WINDOW_H

int	window_destroy(void *param);

int	window_expose(void *param);

int	window_visibly(void *param);

#endif
