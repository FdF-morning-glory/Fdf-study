/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:58:57 by hogkim            #+#    #+#             */
/*   Updated: 2021/12/30 01:17:04 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	check_index(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*cpystr(char const *s1, char *str, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	while (start <= end)
	{
		str[i] = s1[start];
		start++;
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	i = 0;
	while (check_index(s1[i], set))
		i++;
	start = i;
	end = i;
	while (s1[i])
	{
		if (!check_index(s1[i], set))
			end = i;
		i++;
	}
	str = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!str)
		return (NULL);
	return (cpystr(s1, str, start, end));
}
