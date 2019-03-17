/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdellast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:55:28 by ahugh             #+#    #+#             */
/*   Updated: 2019/02/04 11:05:25 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void		ft_lstdellast(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*head;

	head = 0;
	if (alst && del && *alst)
	{
		if ((*alst)->next)
		{
			head = *alst;
			while (head->next)
				head = head->next;
			ft_lstdelone(&head, del);
		}
		else
			ft_lstdelone(alst, del);
	}
}
