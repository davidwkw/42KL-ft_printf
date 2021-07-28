/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwang <kwang@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:39:32 by kwang             #+#    #+#             */
/*   Updated: 2021/05/24 14:52:57 by kwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*next;

	if (*lst && del)
	{
		temp = *lst;
		while (temp)
		{
			next = (*temp).next;
			del((*temp).content);
			free(temp);
			temp = next;
		}
		*lst = NULL;
	}
}
