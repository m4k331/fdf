/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mods.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 18:41:01 by djon-con          #+#    #+#             */
/*   Updated: 2019/03/28 23:29:17 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void inline	press_more_keys(int key, void *vault)
{
	if (key == 125 || key == 126)
		change_height(key, &((t_va*)vault)->mods.height);
	else if (key == 1)
		((t_va*)vault)->mods.shleif *= -1;
	else if (((t_va*)vault)->mods.projection == PERSPECTIVE &&\
			(key == 78 || key == 69 || key == 24 || key == 27))
		change_perspective_dist(key, &((t_va*)vault)->mods.persp_dist);
	else if (key == 8)
		((t_va*)vault)->mods.colorize *= -1;
}

int					press_key(int key, void *vault)
{
	if (key == 53)
		ft_exit(42);
	else if (key >= 12 && key <= 17)
		rotate(key, &((t_va*)vault)->mods.rotation);
	else if (key == 35)
		((t_va*)vault)->mods.projection = PERSPECTIVE;
	else if (key == 34)
	{
		((t_va*)vault)->mods.projection = ISOMETRIC;
		change_rotation(&((t_va*)vault)->mods.rotation, -30, -30, -30);
	}
	else if (key == 82 || key == 29)
		ft_reset(&((t_va*)vault)->mods);
	else if (key == 31)
		((t_va*)vault)->mods.projection = PARALLEL;
	else
		press_more_keys(key, vault);
	img_refresh(vault);
	return (1);
}
