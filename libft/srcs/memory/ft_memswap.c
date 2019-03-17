/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:49:35 by ahugh             #+#    #+#             */
/*   Updated: 2019/03/06 23:16:54 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_memswap(void *a, void *b, int size)
{
	unsigned char	*pa;
	unsigned char	*pb;
	unsigned char	tmp;

	pa = a;
	pb = b;
	if (size == 1)
		ft_swap8((uint8_t*)a, (uint8_t*)b);
	else if (size == 2)
		ft_swap16((uint16_t*)a, (uint16_t*)b);
	else if (size == 4)
		ft_swap32((uint32_t*)a, (uint32_t*)b);
	else if (size == 8)
		ft_swap64((uint64_t*)a, (uint64_t*)b);
	else
		while (size--)
		{
			tmp = *pa;
			*pa = *pb;
			*pb = tmp;
			pa++;
			pb++;
		}
}
