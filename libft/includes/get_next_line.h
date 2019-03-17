/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:42:02 by djon-con          #+#    #+#             */
/*   Updated: 2018/12/18 17:33:16 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1

# include <fcntl.h>
# include "libft.h"

typedef struct	s_bobr
{
	long long	size;
	long long	linesize;
	char		*buf;
}				t_bobr;

int				get_next_line(const int fd, char **line);

#endif
