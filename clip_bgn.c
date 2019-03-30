/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clip_bgn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:57:08 by ahugh             #+#    #+#             */
/*   Updated: 2019/03/27 21:27:55 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void		clip_bgn_top(t_img *img, t_px *bgn, t_px *end)
{
	t_px	curr;
	int		delta_x;
	int		delta_y;

	curr.x = bgn->x;
	curr.y = bgn->y;
	curr.color = bgn->color;
	delta_x = end->x - bgn->x;
	delta_y = end->y - bgn->y;
	bgn->x = bgn->x + delta_x * ((img->height - 2) - bgn->y) / delta_y;
	bgn->y = img->height - 2;
	if (ABS(delta_x) > ABS(delta_y))
		bgn->color = get_color_h(&curr, end, bgn->x, 1);
	else
		bgn->color = get_color_v(&curr, end, bgn->y, 1);
}

void		clip_bgn_bottom(t_img *img, t_px *bgn, t_px *end)
{
	t_px	curr;
	int		delta_x;
	int		delta_y;

	curr.x = bgn->x;
	curr.y = bgn->y;
	curr.color = bgn->color;
	delta_x = end->x - bgn->x;
	delta_y = end->y - bgn->y;
	bgn->x = bgn->x - delta_x * bgn->y / delta_y;
	bgn->y = 0;
	if (ABS(delta_x) > ABS(delta_y))
		bgn->color = get_color_h(&curr, end, bgn->x, 1);
	else
		bgn->color = get_color_v(&curr, end, bgn->y, 1);
}

void		clip_bgn_right(t_img *img, t_px *bgn, t_px *end)
{
	t_px	curr;
	int		delta_x;
	int		delta_y;

	curr.x = bgn->x;
	curr.y = bgn->y;
	curr.color = bgn->color;
	delta_x = end->x - bgn->x;
	delta_y = end->y - bgn->y;
	bgn->y = bgn->y + delta_y * ((img->width - 1) - bgn->x) / delta_x;
	bgn->x = img->width - 1;
	if (ABS(delta_x) > ABS(delta_y))
		bgn->color = get_color_h(&curr, end, bgn->x, 1);
	else
		bgn->color = get_color_v(&curr, end, bgn->y, 1);
}

void		clip_bgn_left(t_img *img, t_px *bgn, t_px *end)
{
	t_px	curr;
	int		delta_x;
	int		delta_y;

	curr.x = bgn->x;
	curr.y = bgn->y;
	curr.color = bgn->color;
	delta_x = end->x - bgn->x;
	delta_y = end->y - bgn->y;
	bgn->y = bgn->y - delta_y * bgn->x / delta_x;
	bgn->x = 0;
	if (ABS(delta_x) > ABS(delta_y))
		bgn->color = get_color_h(&curr, end, bgn->x, 1);
	else
		bgn->color = get_color_v(&curr, end, bgn->y, 1);
}
