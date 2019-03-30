/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 17:35:02 by ahugh             #+#    #+#             */
/*   Updated: 2019/03/28 23:22:29 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int			red_close(void *param)
{
	(void)param;
	del_vault((t_va*)param);
	exit(1);
	return (0);
}

int			mouse_move(int x, int y, void *param)
{
	if (((t_va*)param)->mouse.move)
	{
		((t_va*)param)->mods.offset.x += (x - ((t_va*)param)->mouse.start.x);
		((t_va*)param)->mods.offset.y += (y - ((t_va*)param)->mouse.start.y);
		img_refresh(param);
		((t_va*)param)->mouse.start.x = x;
		((t_va*)param)->mouse.start.y = y;
	}
	return (1);
}

int			mouse_release(int button, int x, int y, void *param)
{
	if (button == 1)
		((t_va*)param)->mouse.move = 0;
	return (1);
}

int			mouse_press(int key, int x, int y, void *param)
{
	if (key == 4 && ((t_va*)param)->mods.scale < MAX_SCALE)
	{
		((t_va*)param)->mods.scale += ZOOM;
		img_refresh(param);
	}
	else if (key == 5 && ((t_va*)param)->mods.scale > MIN_SCALE)
	{
		((t_va*)param)->mods.scale -= ZOOM;
		img_refresh(param);
	}
	else if (key == 1)
	{
		((t_va*)param)->mouse.move = 1;
		((t_va*)param)->mouse.start.x = x;
		((t_va*)param)->mouse.start.y = y;
	}
	return (x + y);
}
