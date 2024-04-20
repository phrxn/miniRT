/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:09:42 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/04/13 21:27:09 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_params.h"
#include "minirt.h"

int	main(int argc, char *argv[])
{
	t_minirt	minirt;

	check_params(argc, argv);
	return (0);
}
