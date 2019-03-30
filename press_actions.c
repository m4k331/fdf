/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 19:50:52 by djon-con          #+#    #+#             */
/*   Updated: 2019/03/28 22:35:06 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int		rotate(int key, t_dot *rot)
{
	if (key == 12)
		rot->x = (rot->x + ROT_SPEED) % 360;
	else if (key == 13)
		rot->x = (rot->x - ROT_SPEED) % 360;
	else if (key == 14)
		rot->y = (rot->y + ROT_SPEED) % 360;
	else if (key == 15)
		rot->y = (rot->y - ROT_SPEED) % 360;
	else if (key == 16)
		rot->z = (rot->z + ROT_SPEED) % 360;
	else if (key == 17)
		rot->z = (rot->z - ROT_SPEED) % 360;
	return (1);
}

void	change_height(int key, float *height)
{
	if (key == 125)
		(*height) -= 0.1;
	else
		(*height) += 0.1;
}

void	change_rotation(t_dot *rotation, int x, int y, int z)
{
	rotation->x = x;
	rotation->y = y;
	rotation->z = z;
}

void	change_perspective_dist(int key, int *dist)
{
	if (key == 78 || key == 27)
		*dist += 10;
	else
		*dist -= 10;
}

void	ft_reset(t_mod *mods)
{
	change_rotation(&mods->rotation, 0, 0, 0);
	mods->scale = SCALE;
	mods->height = 1;
	mods->persp_dist = PERSP_DIST;
}
