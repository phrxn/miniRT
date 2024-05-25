/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_keyboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 22:00:15 by gacalaza          #+#    #+#             */
/*   Updated: 2024/05/25 18:12:04 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_keyboard.h"
#include "minirt.h"
#include "exit.h"

int	key_pressed(int key, void *param)
{
	t_minirt	*minirt;

	minirt = (t_minirt *)param;
	(void)key;
	if (key == VK_ESC)
		terminate(minirt); ///mudar essa funcao tmb!!!!!!

	return (0);
}
