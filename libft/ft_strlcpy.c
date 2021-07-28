/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwang <kwang@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:07:25 by kwang             #+#    #+#             */
/*   Updated: 2021/05/24 13:21:12 by kwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	if (dst && src)
	{
		src_len = ft_strlen(src);
		if (dstsize > 0)
		{
			i = 0;
			while (i < dstsize - 1 && src[i])
			{
				dst[i] = src[i];
				i++;
			}
			dst[i] = '\0';
		}
		return (src_len);
	}
	return (0);
}
