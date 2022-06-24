/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_atoi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:48:36 by jinypark          #+#    #+#             */
/*   Updated: 2022/06/17 15:56:38 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

static int	num_count(const char *str)
{
	unsigned long	nbr;
	int				n;
	int				i;

	nbr = 0;
	i = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		n = str[i] - '0';
		if ((nbr > LONG_MAX / 10 || \
			(nbr == LONG_MAX / 10 && n > LONG_MAX % 10)))
			return ((int)LONG_MAX);
		nbr = nbr * 10 + n;
		i++;
	}
	if (str[i] != '\0' && !ft_isdigit(str[i]))
		return (0);
	return (nbr);
}

int	ft_minitalk_atoi(const char *str)
{
	return (num_count(str));
}
