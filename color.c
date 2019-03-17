/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 12:43:19 by ahugh             #+#    #+#             */
/*   Updated: 2019/03/17 23:00:55 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int				get_color(t_px *bgn, t_px *end, int pos, float transparency)
{
	float		dst;
	float		tgt;
	int			r;
	int			g;
	int			b;

	tgt = bgn->x != end->x ? pos - bgn->x : pos - bgn->y;
	dst = bgn->x != end->x ? end->x - bgn->x : end->y - bgn->y;
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
