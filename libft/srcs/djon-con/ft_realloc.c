/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 04:24:23 by djon-con          #+#    #+#             */
/*   Updated: 2018/12/09 04:44:40 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*tmp;

	if (!(tmp = ft_strnew(size)))
		return (ptr);
	ft_memmove(tmp, ptr, size);
	free(ptr);
	return (tmp);
}
