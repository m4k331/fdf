/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:20:56 by djon-con          #+#    #+#             */
/*   Updated: 2019/03/28 15:54:20 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	apply_perspective(t_dot *dot, t_mod *mods)
{
	float		dz;

	dz = mods->persp_dist - dot->z;
	dot->x = round(mods->persp_dist * dot->x / dz);
	dot->y = round(mods->persp_dist * dot->y / dz);
}

void		apply_projection(t_dot *dot, t_mod *mods)
{
	if (mods->projection == PERSPECTIVE)
		apply_perspective(dot, mods);
}
