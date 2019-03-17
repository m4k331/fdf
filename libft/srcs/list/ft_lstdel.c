/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:37:32 by ahugh             #+#    #+#             */
/*   Updated: 2019/02/04 11:05:14 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void		ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*previous;

	if (!(previous = NULL) && alst && del)
	{
		while ((previous = *alst))
		{
			*alst = (*alst)->next;
			ft_lstdelone(&previous, del);
		}
		*alst = NULL;
	}
}
