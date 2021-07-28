/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwang <kwang@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:08:17 by kwang             #+#    #+#             */
/*   Updated: 2021/07/11 00:49:37 by kwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*joinedstr;
	unsigned int	i;
	unsigned int	j;

	if (s1 && s2)
	{
		joinedstr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!joinedstr)
			return (joinedstr);
		i = 0;
		while (s1[i])
		{
			joinedstr[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j])
		{
			joinedstr[i + j] = s2[j];
			j++;
		}
		joinedstr[i + j] = '\0';
		return (joinedstr);
	}
	return (ft_strdup(""));
}
