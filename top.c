/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 12:46:00 by ahugh             #+#    #+#             */
/*   Updated: 2019/03/27 22:19:33 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

const int		t80(t_img *img, t_px *bgn, t_px *end)
{
	clip_bgn_bottom(img, bgn, end);
	return (1);
}

const int		t82(t_img *img, t_px *bgn, t_px *end)
{
	clip_bgn_bottom(img, bgn, end);
	if (bgn->x > img->width - 1)
		return (0);
	clip_end_right(img, bgn, end);
	return (1);
}

const int		t84(t_img *img, t_px *bgn, t_px *end)
{
	clip_bgn_bottom(img, bgn, end);
	clip_end_bottom(img, bgn, end);
	return (1);
}

const int		t86(t_img *img, t_px *bgn, t_px *end)
{
	clip_bgn_bottom(img, bgn, end);
	if (bgn->x > img->width - 1)
		return (0);
	clip_end_right(img, bgn, end);
	if (end->y > img->height - 2)
		clip_end_bottom(img, bgn, end);
	return (1);
}
