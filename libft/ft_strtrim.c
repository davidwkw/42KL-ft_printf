/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwang <kwang@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:28:43 by kwang             #+#    #+#             */
/*   Updated: 2021/07/11 00:59:17 by kwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_char_in_set(char c, const char *set)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*trimmedstr;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	if (!s1)
		return (ft_strdup(""));
	if (!set)
		return (ft_strdup((char *) s1));
	j = ft_strlen(s1);
	while (is_char_in_set(s1[i], set))
		i++;
	if (i == j)
		return (ft_strdup(""));
	while (is_char_in_set(s1[j - 1], set))
		j--;
	trimmedstr = malloc(sizeof(char) * (j - i) + 1);
	if (!trimmedstr)
		return (trimmedstr);
	k = 0;
	while (i < j)
		trimmedstr[k++] = s1[i++];
	trimmedstr[k] = '\0';
	return (trimmedstr);
}
