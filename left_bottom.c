/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_bottom_p1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 23:28:06 by ahugh             #+#    #+#             */
/*   Updated: 2019/03/27 22:59:13 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

const int		lb50(t_img *img, t_px *bgn, t_px *end)
{
	clip_bgn_left(img, bgn, end);
	if (bgn->y - end->y == 0)
		bgn->y = img->height - 2;
	if (bgn->y > img->height - 2)
		clip_bgn_top(img, bgn, end);
	return (1);
}

const int		lb52(t_img *img, t_px *bgn, t_px *end)
{
	clip_end_right(img, bgn, end);
	if (end->y > img->height - 2)
		return (0);
	clip_bgn_top(img, bgn, end);
	return (1);
}

const int		lb58(t_img *img, t_px *bgn, t_px *end)
{
	clip_end_top(img, bgn, end);
	if (end->x < 0)
		return (0);
	clip_bgn_top(img, bgn, end);
	if (bgn->x < 0)
		clip_bgn_left(img, bgn, end);
	return (1);
}

const int		lb5a(t_img *img, t_px *bgn, t_px *end)
{
	clip_bgn_left(img, bgn, end);
	if (bgn->y < 0)
		return (0);
	clip_end_right(img, bgn, end);
	if (end->y > img->height - 2)
		return (0);
	if (bgn->y > img->height - 2)
		clip_bgn_top(img, bgn, end);
	if (end->y <= 0)
		clip_end_top(img, bgn, end);
	return (1);
}
