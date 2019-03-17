/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 12:06:51 by ahugh             #+#    #+#             */
/*   Updated: 2019/02/04 12:53:18 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list			*ft_lstjoin(t_list *alst, t_list *blst)
{
	t_list		*head;

	head = 0;
	if (alst)
	{
		head = alst;
		if (blst)
		{
			while (alst->next)
				alst = alst->next;
			while (blst)
			{
				alst->next = blst;
				blst = blst->next;
				alst = alst->next;
			}
			alst->next = blst;
		}
	}
	else if (blst)
		head = blst;
	return (head);
}
