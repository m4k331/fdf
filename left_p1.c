/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_p1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:08:54 by ahugh             #+#    #+#             */
/*   Updated: 2019/03/27 23:04:14 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

const int		l16(t_img *img, t_px *bgn, t_px *end)
{
	clip_bgn_left(img, bgn, end);
	if (bgn->y > img->height - 2)
		return (0);
	clip_end_bottom(img, bgn, end);
	if (end->x > img->width - 1)
		clip_end_right(img, bgn, end);
	return (1);
}

const int		l18(t_img *img, t_px *bgn, t_px *end)
{
	clip_bgn_left(img, bgn, end);
	if (bgn->y < 0)
		return (0);
	clip_end_top(img, bgn, end);
	return (1);
}

const int		l1a(t_img *img, t_px *bgn, t_px *end)
{
	clip_bgn_left(img, bgn, end);
	if (bgn->y < 0)
		return (0);
	clip_end_top(img, bgn, end);
	if (end->x > img->width - 1)
		clip_end_right(img, bgn, end);
	return (1);
}
