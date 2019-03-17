/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vnew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:05:48 by ahugh             #+#    #+#             */
/*   Updated: 2019/02/26 14:35:54 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector		*ft_vnew(size_t v_size, size_t type_size)
{
	t_vector	*v;

	v = 0;
	if (v_size && type_size && (v = (t_vector*)malloc(sizeof(t_vector))))
	{
		v->type_size = type_size;
		v->size = v_size;
		v->iter = 0;
		if ((v->const_con = (const void*)malloc(v_size)))
			v->con = (void*)v->const_con;
		else
			ft_memdel((void**)&v);
	}
	return (v);
}
