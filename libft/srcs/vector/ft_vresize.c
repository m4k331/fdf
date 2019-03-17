/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vresize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:37:57 by ahugh             #+#    #+#             */
/*   Updated: 2019/02/26 16:55:46 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_vresize(t_vector *v, size_t v_size)
{
	const void	*con;

	con = 0;
	if (v && v_size)
	{
		if ((con = (const void*)malloc(v_size)))
		{
			ft_memcpy((void*)con, v->const_con, \
					(v_size > v->size ? v->size : v_size));
			if (v->const_con)
				ft_memdel((void**)&v->const_con);
			v->const_con = con;
			v->con = (void*)v->const_con;
			v->size = v_size;
			if (v->iter * v->type_size > v->size)
				v->iter = v->size / v->type_size;
		}
	}
}
