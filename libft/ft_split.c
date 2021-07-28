/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwang <kwang@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 17:58:34 by kwang             #+#    #+#             */
/*   Updated: 2021/06/29 16:25:56 by kwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	i;
	size_t	w_c;

	i = 0;
	w_c = 0;
	if (s && c)
	{
		while (s[i])
		{
			while (s[i] == c)
				i++;
			if (s[i])
				w_c++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (w_c);
}

static char	*ft_stridup(const char *s, size_t n)

{
	char			*dup;
	unsigned int	i;

	dup = malloc(sizeof(char) * n + 1);
	if (!dup)
		return (dup);
	i = 0;
	while (i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	unsigned int	end_index;
	unsigned int	start_index;
	unsigned int	k;

	arr = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!arr)
		return (arr);
	end_index = 0;
	k = 0;
	if (s)
	{
		while (s[end_index])
		{
			while (s[end_index] == c)
				end_index++;
			start_index = end_index;
			while (s[end_index] != c && s[end_index])
				end_index++;
			if (end_index > start_index)
				arr[k++] = ft_stridup(s + start_index, end_index - start_index);
		}
	}
	arr[k] = NULL;
	return (arr);
}
