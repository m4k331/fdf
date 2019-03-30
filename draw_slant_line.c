/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_slant_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:40:09 by ahugh             #+#    #+#             */
/*   Updated: 2019/03/27 22:39:45 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static inline void	draw_to_abscissa(t_img *img, t_px *bgn, t_px *end, float dy)
{
	float			x;
	float			y;
	int				color;

	y = bgn->y;
	x = bgn->x;
	if ((color = bgn->color) == end->color)
		while (x <= end->x)
		{
			y += dy;
			img_pixel_put(img, x, y, set_transparency(color, FPX(y)));
			img_pixel_put(img, x, y + 1, set_transparency(color, SPX(y)));
			x++;
		}
	else
		while (x <= end->x)
		{
			y += dy;
			color = get_color_h(bgn, end, x, FPX(y));
			img_pixel_put(img, x, y, color);
			color = get_color_h(bgn, end, x, SPX(y));
			img_pixel_put(img, x, y + 1, color);
			x++;
		}
}

static inline void	draw_to_ordinate(t_img *img, t_px *bgn, t_px *end, float dx)
{
	float			x;
	float			y;
	int				color;

	y = bgn->y;
	x = bgn->x;
	if ((color = bgn->color) == end->color)
		while (y <= end->y)
		{
			x += dx;
			img_pixel_put(img, x, y, set_transparency(color, FPX(x)));
			img_pixel_put(img, x + 1, y, set_transparency(color, SPX(x)));
			y++;
		}
	else
		while (y <= end->y)
		{
			x += dx;
			color = get_color_v(bgn, end, y, FPX(x));
			img_pixel_put(img, x, y, color);
			color = get_color_v(bgn, end, y, SPX(x));
			img_pixel_put(img, x + 1, y, color);
			y++;
		}
}

static inline void	draw_rev_ord(t_img *img, t_px *bgn, t_px *end, float dx)
{
	float			x;
	float			y;
	int				color;

	y = bgn->y;
	x = bgn->x;
	if ((color = bgn->color) == end->color)
		while (y >= end->y)
		{
			x -= dx;
			img_pixel_put(img, x, y, set_transparency(color, FPX(x)));
			img_pixel_put(img, x + 1, y, set_transparency(color, SPX(x)));
			y--;
		}
	else
		while (y >= end->y)
		{
			x -= dx;
			color = get_color_v(bgn, end, y, FPX(x));
			img_pixel_put(img, x, y, color);
			color = get_color_v(bgn, end, y, SPX(x));
			img_pixel_put(img, x + 1, y, color);
			y--;
		}
}

void				draw_slant_line(t_img *img, t_px *bgn, t_px *end)
{
	float			dx;
	float			dy;

	if (bgn->x > end->x)
		swap_coords(&bgn, &end);
	if (fc_line(img, bgn, end))
		return ;
	dx = (float)(end->x - bgn->x);
	dy = (float)(end->y - bgn->y);
	if (ABS(dy) < ABS(dx))
		draw_to_abscissa(img, bgn, end, dy / dx);
	else
	{
		if (bgn->x == end->x || bgn->y == end->y)
			draw_straight_line(img, bgn, end);
		else if (bgn->y < end->y)
			draw_to_ordinate(img, bgn, end, dx / dy);
		else
			draw_rev_ord(img, bgn, end, dx / dy);
	}
}
