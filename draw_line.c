/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:33:40 by ahugh             #+#    #+#             */
/*   Updated: 2019/03/17 23:02:44 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <stdio.h>

static inline void	draw_straight_line(t_img *img, t_px *bgn, t_px *end)
{
	int				x;
	int				y;

	x = bgn->x;
	y = bgn->y;
	if (bgn->color == end->color)
	{
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
	else
	{
		if (bgn->x == end->x)
			while (y <= end->y)
			{
				img_pixel_put(img, x, y, get_color(bgn, end, y, 1));
				y++;
			}
		else
			while (x <= end->x)
			{
				img_pixel_put(img, x, y, get_color(bgn, end, x, 1));
				x++;
			}
	}
}

static inline void	draw_slant_line_sm(t_img *img, t_px *bgn, t_px *end)
{
	int				steep;
	int				x;
	float			dy;
	float			y;

	printf("before: bgn[%d, %d]\tend[%d, %d]\t", bgn->x, bgn->y, end->x, end->y);
	steep = is_steep_line(bgn, end);
	printf("after: bgn[%d, %d]\tend[%d, %d]\n", bgn->x, bgn->y, end->x, end->y);
	dy = (float)(end->y - bgn->y) / (float)(end->x - bgn->x);
	y = (float)bgn->y;
	if (bgn->y < end->y && bgn->x <= end->x)
	{
		x = bgn->x - 1;
		while (++x <= end->x)
		{
			y += dy;
			printf("1.y=%f\tdy=%f\n", y, dy);
			if (steep)
			{
				img_pixel_put(img, (int)y + 1, x, (bgn->color == end->color \
						? bgn->color : get_color(bgn, end, x, y - (int)y)));
				img_pixel_put(img, (int)y, x, (bgn->color == end->color \
						? bgn->color : get_color(bgn, end, x, 1.0 - (y - (int)y))));
			}
			else
			{
				img_pixel_put(img, x, (int)y, (bgn->color == end->color \
						? bgn->color : get_color(bgn, end, x, 1.0 - (y - (int)y))));
				img_pixel_put(img, x, (int)y + 1, (bgn->color == end->color \
						? bgn->color : get_color(bgn, end, x, y - (int)y)));
			}
		}
	}
	else
	{
		x = bgn->x + 1;
		printf("%d >= %d\n", x, end->x);
		while (--x >= end->x)
		{
			y += dy;
			printf("2.y=%f\tdy=%f\n", y, dy);
			if (steep)
			{
				img_pixel_put(img, (int)y + 1, x, (bgn->color == end->color \
						? bgn->color : get_color(bgn, end, x, y - (int)y)));
				img_pixel_put(img, (int)y, x, (bgn->color == end->color \
						? bgn->color : get_color(bgn, end, x, 1.0 - (y - (int)y))));
			}
			else
			{
				img_pixel_put(img, x, (int)y, (bgn->color == end->color \
						? bgn->color : get_color(bgn, end, x, 1.0 - (y - (int)y))));
				img_pixel_put(img, x, (int)y + 1, (bgn->color == end->color \
						? bgn->color : get_color(bgn, end, x, y - (int)y)));
			}
		}
	}
}

int					draw_line_smoothing(t_img *img, t_px *bgn, t_px *end)
{
	if (bgn->x == end->x || bgn->y == end->y)
	{
		if (bgn->y > end->y || bgn->x > end->x)
			ft_swap64((uint64_t*)bgn, (uint64_t*)end);
		// check and fix edge coords
		draw_straight_line(img, bgn, end);
	}
	else
	{
		if (bgn->x > end->x)
			ft_swap64((uint64_t*)bgn, (uint64_t*)end);
		// check and fix edge coords
		draw_slant_line_sm(img, bgn, end);
	}
	return (0);
}
