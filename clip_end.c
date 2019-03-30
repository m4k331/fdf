/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clip_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 22:02:31 by ahugh             #+#    #+#             */
/*   Updated: 2019/03/27 21:27:58 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void		clip_end_bottom(t_img *img, t_px *bgn, t_px *end)
{
	t_px	curr;
	int		delta_x;
	int		delta_y;

	curr.x = end->x;
	curr.y = end->y;
	curr.color = end->color;
	delta_x = bgn->x - end->x;
	delta_y = bgn->y - end->y;
	if (delta_y)
		end->x = end->x + delta_x * ((img->height - 2) - end->y) / delta_y;
	else
		end->x = bgn->x < end->x ? 0 : img->width - 1;
	end->y = img->height - 2;
	if (ABS(delta_x) > ABS(delta_y))
		end->color = get_color_h(bgn, &curr, end->x, 1);
	else
		end->color = get_color_v(bgn, &curr, end->y, 1);
}

void		clip_end_top(t_img *img, t_px *bgn, t_px *end)
{
	t_px	curr;
	int		delta_x;
	int		delta_y;

	curr.x = end->x;
	curr.y = end->y;
	curr.color = end->color;
	delta_x = bgn->x - end->x;
	delta_y = bgn->y - end->y;
	if (delta_y)
		end->x = end->x - delta_x * end->y / delta_y;
	else
		end->x = bgn->x < end->x ? 0 : img->width - 1;
	end->y = 1;
	if (ABS(delta_x) > ABS(delta_y))
		end->color = get_color_h(bgn, &curr, end->x, 1);
	else
		end->color = get_color_v(bgn, &curr, end->y, 1);
}

void		clip_end_right(t_img *img, t_px *bgn, t_px *end)
{
	t_px	curr;
	int		delta_x;
	int		delta_y;

	curr.x = end->x;
	curr.y = end->y;
	curr.color = end->color;
	delta_x = bgn->x - end->x;
	delta_y = bgn->y - end->y;
	if (delta_x)
		end->y = end->y + (delta_y) * ((img->width - 1) - end->x) / delta_x;
	else
		end->y = bgn->y < end->y ? 1 : img->height - 2;
	end->x = img->width - 2;
	if (ABS(delta_x) > ABS(delta_y))
		end->color = get_color_h(bgn, &curr, end->x, 1);
	else
		end->color = get_color_v(bgn, &curr, end->y, 1);
}
