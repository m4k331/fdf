/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:25:33 by djon-con          #+#    #+#             */
/*   Updated: 2018/12/11 20:36:08 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrm(t_list **lst, t_list **todel)
{
	if (!lst || !*lst || !todel || !*todel)
		return ;
	if (*lst == *todel)
		*lst = (*lst)->next;
	else
	{
		while ((*lst)->next != *todel)
		{
			*lst = (*lst)->next;
			if (!(*lst)->next)
				return ;
		}
		(*lst)->next = (*lst)->next->next;
	}
	ft_lstdelone(todel, NULL);
}
