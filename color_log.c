/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 19:49:52 by djon-con          #+#    #+#             */
/*   Updated: 2019/03/28 19:50:20 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static int	log_neg(int z)
{
	t_px color[6];

	set_px(&color[0], 0, 0, GREEN);
	set_px(&color[1], 10, 0, AQUA);
	set_px(&color[2], 20, 0, SKY);
	set_px(&color[3], 50, 0, PINK);
	set_px(&color[4], 100, 0, RO_BLUE);
	set_px(&color[5], 1000, 0, ORCHID);
	if (z > 100)
		return (get_color_h(&color[4], &color[5], z, 1));
	else if (z > 50)
		return (get_color_h(&color[3], &color[4], z, 1));
	else if (z > 20)
		return (get_color_h(&color[2], &color[3], z, 1));
	else if (z > 10)
		return (get_color_h(&color[1], &color[2], z, 1));
	else
		return (get_color_h(&color[0], &color[1], z, 1));
}

static int	log_pos(int z)
{
	t_px color[6];

	set_px(&color[0], 0, 0, GREEN);
	set_px(&color[1], 10, 0, YELLOW);
	set_px(&color[2], 20, 0, GOLD);
	set_px(&color[3], 50, 0, KHAKI);
	set_px(&color[4], 100, 0, SALMON);
	set_px(&color[5], 1000, 0, CRIMSON);
	if (z > 100)
		return (get_color_h(&color[4], &color[5], z, 1));
	else if (z > 50)
		return (get_color_h(&color[3], &color[4], z, 1));
	else if (z > 20)
		return (get_color_h(&color[2], &color[3], z, 1));
	else if (z > 10)
		return (get_color_h(&color[1], &color[2], z, 1));
	else
		return (get_color_h(&color[0], &color[1], z, 1));
}

int			color_log(int z)
{
	if (z < 0)
		return (log_neg(-z));
	else
		return (log_pos(z));
}
