/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vpush_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:32:17 by ahugh             #+#    #+#             */
/*   Updated: 2019/02/26 14:36:21 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_vpush_back(t_vector *v, void *val, size_t val_size)
{
	size_t	free;
	size_t	old_size;

	free = v->size - v->iter * v->type_size;
	old_size = v->size;
	if (v && val && val_size)
	{
		if (val_size > free)
			while (v->size - v->iter * v->type_size <= free)
			{
				ft_vresize(v, v->size * EXPAND);
				if (old_size == v->size)
					return ;
				old_size = v->size;
			}
		ft_memcpy(&v->con[v->iter], val, val_size);
		v->iter += val_size / v->type_size;
	}
}
