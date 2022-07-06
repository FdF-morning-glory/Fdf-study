/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:12:14 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/30 20:20:45 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	**words_clear(char **words)
{
	int	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
	return (NULL);
}

char	**words_dup(char const *s, char const *set, char **words)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (s[i] && j < ft_word_count(s, set))
	{
		while (s[i] && is_set(s[i], set))
			i++;
		len = 0;
		while (s[i] && !is_set(s[i], set))
		{
			len++;
			i++;
		}
		words[j] = (char *)malloc(sizeof(char) * (len + 1));
		if (!words[j])
		{
			words_clear(words);
			return (NULL);
		}
		ft_strlcpy(words[j++], s + (i - len), len + 1);
	}
	return (words);
}

char	**ft_split(char const *s, char const *set)
{
	char	**words;
	int		count;

	if (!s)
		return (NULL);
	count = ft_word_count(s, set);
	words = (char **)malloc(sizeof(char *) * (count + 1));
	if (!words)
		return (NULL);
	words = words_dup(s, set, words);
	if (!words)
		return (NULL);
	words[count] = NULL;
	return (words);
}
