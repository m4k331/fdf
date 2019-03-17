/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 23:45:04 by djon-con          #+#    #+#             */
/*   Updated: 2018/12/14 18:49:27 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	t_list		*lst_find_size(t_list *list, size_t content_size)
{
	if (!list)
		return (NULL);
	while (list && (list)->content_size != content_size)
		list = (list)->next;
	return (list);
}

static t_bobr		*ft_bobrnew(void)
{
	t_bobr	*tmp;

	if (!(tmp = (t_bobr*)malloc(sizeof(t_bobr))))
		return (NULL);
	tmp->size = 0;
	tmp->buf = ft_strnew(BUFF_SIZE);
	return (tmp);
}

int					ft_read_line(t_bobr *bobr, char **tmp, long long i, int fd)
{
	long long n;

	n = 0;
	while (bobr->buf[i] != '\n' && i < bobr->size)
	{
		if (bobr->buf[i] != '\n' && n == bobr->linesize - 1)
		{
			bobr->linesize *= 2;
			*tmp = ft_realloc(*tmp, bobr->linesize);
		}
		(*tmp)[n] = bobr->buf[i];
		n++;
		i++;
		if (i == bobr->size && bobr->buf[i - 1] != '\n')
		{
			if ((bobr->size = read(fd, bobr->buf, BUFF_SIZE)) == -1)
				return (-1);
			i = 0;
		}
	}
	(*tmp)[n] = 0;
	return (i);
}

int					fill_line(char **line, t_bobr *bobr, int fd)
{
	long long	i;
	char		*tmp;

	bobr->linesize = 2;
	i = 0;
	if (bobr->size == 0)
		if ((bobr->size = read(fd, bobr->buf, BUFF_SIZE)) == 0)
			return (0);
	if (bobr->size != -1 && (tmp = ft_strnew(bobr->linesize)))
	{
		if ((i = ft_read_line(bobr, &tmp, i, fd)) != -1)
		{
			if (bobr->buf[i] == '\n' && i < bobr->size)
				bobr->size = bobr->size - (i + 1);
			bobr->buf = ft_memmove(bobr->buf, bobr->buf + (i + 1), bobr->size);
			if ((*line = ft_memalloc(bobr->linesize)))
			{
				ft_memmove(*line, tmp, bobr->linesize);
				free(tmp);
				return (1);
			}
		}
	}
	return (-1);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*full = NULL;
	t_list			*lst;
	t_bobr			*bobr;
	int				i;

	if (fd < 0 || BUFF_SIZE < 1 || !line)
		return (-1);
	lst = NULL;
	if ((lst = lst_find_size(full, fd)) == NULL)
	{
		if (!(bobr = ft_bobrnew()))
			return (-1);
		lst = ft_lstnew(NULL, 0);
		lst->content = bobr;
		ft_lstadd(&full, lst);
		lst->content_size = fd;
	}
	i = fill_line(line, lst->content, fd);
	if ((i == -1 || i == 0) && lst->content)
	{
		free((((t_bobr*)lst->content)->buf));
		ft_lstrm(&full, &lst);
	}
	return (i);
}
