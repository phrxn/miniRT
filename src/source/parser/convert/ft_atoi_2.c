/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:07:26 by dmanoel-          #+#    #+#             */
/*   Updated: 2024/05/21 13:17:07 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atoi_2.h"
#include "convert_errors.h"
#include "libft.h"

static int	ft_isblank(char a)
{
	return ((a == '\n')
		|| (a == '\v')
		|| (a == '\f')
		|| (a == '\t')
		|| (a == '\r')
		|| (a == ' '));
}

int	ft_atoi_2(const char *str, int *status)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	*status = OK_CONVERT;
	while (ft_isblank(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		res = (*str - 48) + res * 10;
		if ((res > MAX_INT && sign == 1) || (res > OVERFLOW && sign == -1))
			*status = ERR_OVER_UNDER;
		str++;
	}
	return (sign * res);
}
