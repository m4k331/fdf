/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 12:43:19 by ahugh             #+#    #+#             */
/*   Updated: 2019/03/28 16:02:48 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int				get_color_h(t_px *bgn, t_px *end, int pos, float transparency)
{
	float		dst;
	float		tgt;
	int			r;
	int			g;
	int			b;

	tgt = pos - bgn->x;
	dst = end->x - bgn->x;
	dst = (dst ? tgt / dst : 1.0);
	pos = (int)(255.0 - 255.0 * transparency);
	r = (int)(((bgn->color >> 16) & 0xFF) * (1.0 - dst) \
			+ ((end->color >> 16) & 0xFF) * dst);
	g = (int)(((bgn->color >> 8) & 0xFF) * (1.0 - dst) \
			+ ((end->color >> 8) & 0xFF) * dst);
	b = (int)((bgn->color & 0xFF) * (1.0 - dst) \
			+ (end->color & 0xFF) * dst);
	return (pos << 24 | r << 16 | g << 8 | b);
}

int				get_color_v(t_px *bgn, t_px *end, int pos, float transparency)
{
	float		dst;
	float		tgt;
	int			r;
	int			g;
	int			b;

	tgt = pos - bgn->y;
	dst = end->y - bgn->y;
	dst = (dst ? tgt / dst : 1.0);
	pos = (int)(255.0 - 255.0 * transparency);
	r = (int)(((bgn->color >> 16) & 0xFF) * (1.0 - dst) \
			+ ((end->color >> 16) & 0xFF) * dst);
	g = (int)(((bgn->color >> 8) & 0xFF) * (1.0 - dst) \
			+ ((end->color >> 8) & 0xFF) * dst);
	b = (int)((bgn->color & 0xFF) * (1.0 - dst) \
			+ (end->color & 0xFF) * dst);
	return (pos << 24 | r << 16 | g << 8 | b);
}

int				set_transparency(int color, float transparency)
{
	int			a;

	a = (int)(255.0 - 255.0 * transparency);
	return ((color & 0x00FFFFFF) | (a << 24));
}
