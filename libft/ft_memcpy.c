/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwang <kwang@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:41:21 by kwang             #+#    #+#             */
/*   Updated: 2021/05/22 13:05:40 by kwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	if (dst || src)
	{
		d = (char *)dst;
		s = (char *)src;
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
		return (dst);
	}
	return (NULL);
}
