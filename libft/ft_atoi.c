/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:27:13 by hogkim            #+#    #+#             */
/*   Updated: 2022/01/04 16:40:58 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	over_range(unsigned long long int value, int sign)
{
	if (value > 9223372036854775806 && sign == 1)
		return (-1);
	if (value > 9223372036854775807 && sign == -1)
		return (0);
	return (value);
}

int	ft_atoi(const char *str)
{
	size_t					i;
	int						sign;
	unsigned long long int	value;

	sign = 1;
	value = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = 10 * value + str[i] - '0';
		i++;
	}
	value = over_range(value, sign);
	return (sign * value);
}
