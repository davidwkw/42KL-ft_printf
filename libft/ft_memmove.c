/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwang <kwang@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 21:38:31 by kwang             #+#    #+#             */
/*   Updated: 2021/05/22 13:07:32 by kwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;

	if (dst || src)
	{
		d = (char *)dst;
		s = (char *)src;
		if (s < d)
		{
			while (len > 0)
			{
				d[len - 1] = s[len - 1];
				len--;
			}
		}
		else
		{
			ft_memcpy(dst, src, len);
		}
		return (dst);
	}
	return (NULL);
}
