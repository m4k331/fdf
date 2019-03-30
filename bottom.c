/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bottom.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 12:00:29 by ahugh             #+#    #+#             */
/*   Updated: 2019/03/27 22:24:18 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

const int		b40(t_img *img, t_px *bgn, t_px *end)
{
	clip_bgn_top(img, bgn, end);
	return (1);
}

const int		b42(t_img *img, t_px *bgn, t_px *end)
{
	clip_bgn_top(img, bgn, end);
	if (bgn->x > img->width - 1)
		return (0);
	clip_end_right(img, bgn, end);
	return (1);
}

const int		b48(t_img *img, t_px *bgn, t_px *end)
{
	clip_bgn_top(img, bgn, end);
	clip_end_top(img, bgn, end);
	return (1);
}

const int		b4a(t_img *img, t_px *bgn, t_px *end)
{
	clip_bgn_top(img, bgn, end);
	if (bgn->x > img->width - 1)
		return (0);
	clip_end_right(img, bgn, end);
	if (end->y <= 0)
		clip_end_top(img, bgn, end);
	return (1);
}
