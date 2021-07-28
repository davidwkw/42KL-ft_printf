/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwang <kwang@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 23:32:22 by kwang             #+#    #+#             */
/*   Updated: 2021/05/24 13:11:31 by kwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrlen(int n)
{
	size_t	len;
	size_t	posn;

	len = 1;
	posn = n;
	if (n < 0)
	{
		posn *= -1;
		len++;
	}
	while (posn > 10)
	{
		posn /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	size_t	posn;
	size_t	i;

	len = ft_nbrlen(n);
	str = malloc(sizeof(char) * len + 1);
	posn = n;
	if (!str)
		return (str);
	i = 0;
	if (n < 0)
	{
		str[i++] = '-';
		posn *= -1;
	}
	str[len] = '\0';
	while (len > i)
	{
		str[--len] = '0' + posn % 10;
		posn /= 10;
	}
	return (str);
}
