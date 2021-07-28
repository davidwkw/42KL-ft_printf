/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwang <kwang@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 11:10:05 by kwang             #+#    #+#             */
/*   Updated: 2021/06/01 16:27:46 by kwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;

	dup = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dup)
		return (dup);
	ft_strlcpy(dup, s1, ft_strlen(s1) + 1);
	return (dup);
}
