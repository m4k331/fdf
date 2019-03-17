/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vpop_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 22:57:24 by ahugh             #+#    #+#             */
/*   Updated: 2019/02/26 14:36:13 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_vpop_back(t_vector *v)
{
	size_t			bytes;
	size_t			size;

	bytes = 0;
	size = 0;
	if (v)
	{
		if (v->iter)
		{
			bytes = v->type_size;
			size = ft_vsize(v) - 1;
			while (bytes--)
			{
				((unsigned char*)v->con)[size] = 0;
				size--;
			}
			v->iter--;
		}
	}
}
