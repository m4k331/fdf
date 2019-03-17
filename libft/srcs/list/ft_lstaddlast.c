/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:54:14 by ahugh             #+#    #+#             */
/*   Updated: 2019/02/04 11:04:59 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void		ft_lstaddlast(t_list **alst, t_list *new)
{
	t_list	*next;

	next = 0;
	if (alst)
	{
		next = *alst;
		if (next)
		{
			while (next->next)
				next = next->next;
			next->next = new;
		}
		else
			*alst = new;
	}
}
