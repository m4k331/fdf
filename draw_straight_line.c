/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_straight_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:05:34 by ahugh             #+#    #+#             */
/*   Updated: 2019/03/21 17:39:44 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static inline void	draw_signle_color(t_img *img, t_px *bgn, t_px *end)
{
	int				x;
	int				y;

	x = bgn->x;
	y = bgn->y;
	if (bgn->x == end->x)
		while (y <= end->y)
		{
			img_pixel_put(img, x, y, bgn->color);
			y++;
		}
	else
		while (x <= end->x)
		{
			img_pixel_put(img, x, y, bgn->color);
			x++;
		}
}

static inline void	draw_gradient_color(t_img *img, t_px *bgn, t_px *end)
{
	int				x;
	int				y;

	x = bgn->x;
	y = bgn->y;
	if (bgn->x == end->x)
		while (y <= end->y)
		{
			img_pixel_put(img, x, y, get_color_v(bgn, end, y, 1));
			y++;
		}
	else
		while (x <= end->x)
		{
			img_pixel_put(img, x, y, get_color_h(bgn, end, x, 1));
			x++;
		}
}

static inline int	is_visible_line(t_img *img, t_px *bgn, t_px *end)
{
	int				w;
	int				h;

	w = img->width;
	h = img->height - 1;
	if ((NEGATIVE(bgn->x, bgn->y) && NEGATIVE(end->x, end->y)) || \
			(OVER(bgn->x, bgn->y, w, h) && OVER(end->x, end->y, w, h)))
		return (0);
	if (bgn->x < 0)
		bgn->x = 0;
	if (bgn->y < 0)
		bgn->y = 0;
	if (end->x > w)
		end->x = w;
	if (end->y > h)
		end->y = h;
	return (1);
}

void				draw_straight_line(t_img *img, t_px *bgn, t_px *end)
{
	int				x;
	int				y;

	x = bgn->x;
	y = bgn->y;
	if (bgn->x > end->x || bgn->y > end->y)
		swap_coords(&bgn, &end);
	if (is_visible_line(img, bgn, end))
	{
		if (bgn->color == end->color)
			draw_signle_color(img, bgn, end);
		else
			draw_gradient_color(img, bgn, end);
	}
}
