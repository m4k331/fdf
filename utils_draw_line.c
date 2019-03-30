/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 16:54:42 by ahugh             #+#    #+#             */
/*   Updated: 2019/03/28 18:49:23 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void			swap_coords(t_px **bgn, t_px **end)
{
	ft_swap64((uint64_t*)bgn, (uint64_t*)end);
}

/*
** Visible area of the window is under code 0000
**
** 1001 | 1000 | 1010
** -----|------|-----
** 0001 | 0000 | 0010
** -----|------|-----
** 0101 | 0100 | 0110
*/

int				get_code_px(t_img *img, t_px *px)
{
	return ((px->x <= 0) | \
			((px->x > img->width - 1) << 1) | \
			((px->y > img->height - 1) << 2) | \
			((px->y <= 0) << 3));
}

int				fc_line(t_img *img, t_px *bgn, t_px *end)
{
	const int	(*fc[151])(t_img*, t_px*, t_px*) = {c0, 0, c2, 0, c4, 0, c6, \
		0, c8, 0, ca, 0, 0, 0, 0, 0, l10, 0, l12, 0, l14, 0, l16, \
			0, l18, 0, l1a, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
			0, 0, 0, 0, 0, 0, b40, 0, b42, 0, 0, 0, 0, 0, b48, 0, \
			b4a, 0, 0, 0, 0, 0, lb50, 0, lb52, 0, 0, 0, 0, 0, \
			lb58, 0, lb5a, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
			0, 0, 0, 0, 0, 0, t80, 0, t82, 0, t84, 0, t86, 0, 0, \
			0, 0, 0, 0, 0, 0, 0, lt90, 0, lt92, 0, lt94, 0, lt96};
	int			code_bgn;
	int			code_end;
	int			code_line;

	code_bgn = get_code_px(img, bgn);
	code_end = get_code_px(img, end);
	code_line = (code_bgn << 4) | code_end;
	if (code_bgn & code_end)
		return (1);
	if (!fc[code_line](img, bgn, end))
		return (1);
	return (0);
}

void			set_px(t_px *px, int x, int y, int color)
{
	if (px)
	{
		px->x = x;
		px->y = y;
		px->color = color;
	}
}
