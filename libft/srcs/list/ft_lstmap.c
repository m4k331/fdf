/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:20:36 by ahugh             #+#    #+#             */
/*   Updated: 2019/02/04 11:06:24 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static void	ft_delcontent(void *content, size_t content_size)
{
	if (content)
		free(content);
	content_size = 0;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lstmap;
	t_list	*bgnmap;
	t_list	*next;

	lstmap = NULL;
	bgnmap = NULL;
	next = NULL;
	if (lst && f)
		if ((lstmap = f(lst)))
		{
			bgnmap = lstmap;
			while ((lst = lst->next))
				if ((next = f(lst)))
				{
					lstmap->next = next;
					lstmap = lstmap->next;
				}
				else
				{
					ft_lstdel(&bgnmap, &ft_delcontent);
					return (NULL);
				}
		}
	return (bgnmap);
}
