/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mods.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 22:20:26 by djon-con          #+#    #+#             */
/*   Updated: 2019/03/29 14:30:53 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	set_mods(t_va *vault)
{
	vault->mods.persp_dist = PERSP_DIST;
	vault->mods.offset.x = OFFSET_X;
	vault->mods.offset.y = OFFSET_Y;
	vault->mouse.move = 0;
	vault->mods.height = 1.0;
	vault->mods.scale = SCALE;
	vault->mods.projection = ISOMETRIC;
	vault->mods.shleif = -1;
	vault->mods.colorize = 1;
}
