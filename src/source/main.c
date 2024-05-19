/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:09:42 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/18 20:45:05 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_params.h"
#include "minirt.h"

int	main(int argc, char *argv[])
{
	t_minirt	minirt;

	(void)minirt;
	check_params(argc, argv);
	return (0);
}
