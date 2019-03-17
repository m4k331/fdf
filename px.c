/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 20:11:29 by ahugh             #+#    #+#             */
/*   Updated: 2019/03/07 00:08:58 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void			set_px(t_px *px, int x, int y, int color)
{
	if (px)
	{
		px->x = x;
		px->y = y;
		px->color = color;
	}
}

t_px			*get_px(int x, int y, int color)
{
	t_px		*px;

	if ((px = (t_px*)malloc(sizeof(t_px))))
		set_px(px, x, y, color);
	return (px);
}
