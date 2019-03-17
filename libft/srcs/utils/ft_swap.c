/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:39:37 by ahugh             #+#    #+#             */
/*   Updated: 2019/03/06 23:10:43 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_swap8(uint8_t *a, uint8_t *b)
{
	uint8_t		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void			ft_swap16(uint16_t *a, uint16_t *b)
{
	uint16_t	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void			ft_swap32(uint32_t *a, uint32_t *b)
{
	uint32_t	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void			ft_swap64(uint64_t *a, uint64_t *b)
{
	uint64_t	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
