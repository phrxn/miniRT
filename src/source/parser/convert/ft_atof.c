/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:02:06 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/21 16:02:05 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atof.h"
#include "libft.h"

double ft_atof(const char *str)
{
    double	result;
    double	fraction;
    int		sign;

    fraction = 0.1;
    sign = 1;
    result = ft_atoi(str);
    if (result < 0)
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
