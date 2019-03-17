/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcreate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 09:20:11 by ahugh             #+#    #+#             */
/*   Updated: 2019/02/06 09:26:06 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list		*ft_lstcreate(int size)
{
	int		count;
	t_list	*head;
	t_list	*iter;

	count = 0;
	head = 0;
	iter = 0;
	if (!(count++ < size && (head = ft_lstnew(0, 0))))
		return (0);
	iter = head;
	while (count < size)
		if ((iter->next = ft_lstnew(0, 0)) && ++count)
			iter = iter->next;
		else
			break ;
	if (count != size)
		while (head)
		{
			iter = head->next;
			free(head);
			head = iter;
		}
	return (head);
}
