/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_top_p1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 18:03:46 by ahugh             #+#    #+#             */
/*   Updated: 2019/03/27 22:19:45 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

const int		lt90(t_img *img, t_px *bgn, t_px *end)
{
	clip_bgn_left(img, bgn, end);
	if (bgn->y < 0)
		clip_bgn_bottom(img, bgn, end);
	return (1);
}

const int		lt92(t_img *img, t_px *bgn, t_px *end)
{
	clip_end_right(img, bgn, end);
	if (end->y < 1)
		return (0);
	clip_bgn_bottom(img, bgn, end);
	if (bgn->x < 0)
		clip_bgn_left(img, bgn, end);
	return (1);
}

const int		lt94(t_img *img, t_px *bgn, t_px *end)
{
	clip_end_bottom(img, bgn, end);
	if (end->x < 0)
		return (0);
	clip_bgn_left(img, bgn, end);
	if (bgn->y < 0)
		clip_bgn_bottom(img, bgn, end);
	return (1);
}

const int		lt96(t_img *img, t_px *bgn, t_px *end)
{
	clip_bgn_left(img, bgn, end);
	if (bgn->y > img->height - 2)
		return (0);
	clip_end_right(img, bgn, end);
	if (end->y < 1)
		return (0);
	if (bgn->y < 0)
		clip_bgn_bottom(img, bgn, end);
	if (end->y > img->height - 2)
		clip_end_bottom(img, bgn, end);
	return (1);
}
