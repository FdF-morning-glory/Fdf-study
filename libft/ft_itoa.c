/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 21:58:21 by hogkim            #+#    #+#             */
/*   Updated: 2021/12/28 20:30:45 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_abs(long long int nb)
{
	if (nb < 0)
		return (nb * (-1));
	return (nb);
}

size_t	nb_len(long long int nb)
{
	size_t	len;

	len = 0;
	if (nb <= 0)
	{
		len = 1;
		nb *= -1;
	}
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	size_t			i;
	long long int	nb;

	nb = (long long int)n;
	str = (char *)malloc(sizeof(char) * (nb_len(nb) + 1));
	if (!str)
		return (NULL);
	i = nb_len(nb);
	str[i] = 0;
	if (n < 0)
		str[0] = '-';
	nb = ft_abs(nb);
	i--;
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[i] = nb % 10 + '0';
		nb /= 10;
		i--;
	}
	return (str);
}
