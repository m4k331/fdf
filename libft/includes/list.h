/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:56:11 by ahugh             #+#    #+#             */
/*   Updated: 2019/03/12 19:08:20 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# include "libft.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstat(t_list *lst, size_t nbr);
t_list				*ft_lstjoin(t_list *alst, t_list *blst);
t_list				*ft_lstcreate(int size);
t_list				*ft_lstcopy(t_list *lst);
size_t				ft_lstsize(t_list *lst);
void				ft_lstrev(t_list **alst);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstaddlast(t_list **alst, t_list *new);
void				ft_lstdellast(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdelnbr(t_list **alst, void (*del)(void*, size_t), \
																	size_t nbr);
void				ft_lstrm(t_list **lst, t_list **todel);

#endif
