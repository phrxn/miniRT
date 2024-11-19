/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:02:06 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/26 04:30:35 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atof.h"
#include "libft.h"

double	ft_atof(const char *str)
{
	double	result;
	double	fraction;
	int		sign;

	fraction = 0.1;
	sign = 1;
	result = ft_atoi(str);
	if (str[0] == '-')
	{
		sign = -1;
		result *= sign;
	}
	while (*str != '.' && *str)
		str++;
	if (*str == '.')
	{
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result + (*str - '0') * fraction;
		fraction /= 10.0;
		str++;
	}
	return (result *= sign);
}
