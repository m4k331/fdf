/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:20:34 by ahugh             #+#    #+#             */
/*   Updated: 2019/02/04 11:05:38 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void		ft_lstdelnbr(t_list **alst, void (*del)(void*, size_t), size_t nbr)
{
	size_t	iter;
	t_list	*previous;
	t_list	*head;

	iter = 0;
	head = 0;
	previous = 0;
	if (alst && *alst)
	{
		previous = *alst;
		head = nbr ? *alst : (*alst)->next;
		while (iter < nbr && *alst)
		{
			previous = *alst;
			*alst = (*alst)->next;
			iter++;
		}
		if (*alst && iter == nbr)
		{
			previous->next = (*alst)->next;
			ft_lstdelone(alst, del);
		}
		*alst = head;
	}
}
