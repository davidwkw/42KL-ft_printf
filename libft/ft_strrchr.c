/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwang <kwang@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:40:35 by kwang             #+#    #+#             */
/*   Updated: 2021/07/10 01:45:33 by kwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		str_len;
	char	ch;

	ch = (char)c;
	str_len = ft_strlen(s);
	while (str_len >= 0)
	{
		if (s[str_len] == ch)
			return ((char *)s + str_len);
		str_len--;
	}
	return (NULL);
}
