/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mods.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:06:07 by djon-con          #+#    #+#             */
/*   Updated: 2019/03/28 19:20:35 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	apply_resize(t_dot *dot, int scale)
{
	dot->x *= scale;
	dot->y *= scale;
	dot->z *= scale;
}

void	apply_offset(t_dot *dot, t_px coords)
{
	dot->x += coords.x;
	dot->y += coords.y;
}

void	apply_rotation(t_dot *dot, t_dot rotation)
{
	t_dot tmp;

	tmp.x = dot->x;
	tmp.y = dot->y;
	tmp.z = dot->z;
	if (rotation.x != 0)
	{
		dot->y = round(tmp.y * cos(X_RAD) + tmp.z * sin(X_RAD));
		dot->z = round(-1 * tmp.y * sin(X_RAD) + tmp.z * cos(X_RAD));
		tmp.y = dot->y;
		tmp.z = dot->z;
	}
	if (rotation.y != 0)
	{
		dot->x = round(tmp.x * cos(Y_RAD) + tmp.z * sin(Y_RAD));
		dot->z = round(-tmp.x * sin(Y_RAD) + tmp.z * cos(Y_RAD));
		tmp.x = dot->x;
		tmp.z = dot->z;
	}
	if (rotation.z != 0)
	{
		dot->x = round(tmp.x * cos(Z_RAD) + tmp.y * sin(Z_RAD));
		dot->y = round(-1 * tmp.x * sin(Z_RAD) + tmp.y * cos(Z_RAD));
	}
}

void	apply_color(t_dot *dot)
{
	dot->color = color_log(dot->z);
}

void	apply_height(t_dot *dot, float height)
{
	dot->z *= height;
}
