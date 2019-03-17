/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vreadfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:34:31 by ahugh             #+#    #+#             */
/*   Updated: 2019/02/26 16:57:52 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_vreadfile(t_vector *v, int fd, size_t buff_size)
{
	int				rb;

	rb = 64;
	if (v)
	{
		while (rb > 0)
		{
			while (buff_size >= ft_vunused_size(v) && rb-- != 0)
				ft_vresize(v, EXPAND * v->size);
			if (rb == -1)
				return (-1);
			rb = read(fd, ft_vat(v, v->iter), buff_size);
			v->iter += rb;
			((char*)v->con)[v->iter] = 0;
		}
		if (rb != -1)
			return (0);
	}
	return (-1);
}
