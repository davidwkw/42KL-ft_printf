/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwang <kwang@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 18:32:39 by kwang             #+#    #+#             */
/*   Updated: 2021/05/24 15:33:55 by kwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[i])
	{
		while (haystack[i] && i < len)
		{
			j = 0;
			while (i + j < len && (haystack[i + j] == needle[j]) && needle[j])
				j++;
			if (needle[j] == '\0')
				return ((char *)haystack + i);
			i++;
		}
		return (NULL);
	}
	return ((char *)haystack);
}
