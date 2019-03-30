/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_p2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 23:03:13 by ahugh             #+#    #+#             */
/*   Updated: 2019/03/27 23:04:16 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

const int		l10(t_img *img, t_px *bgn, t_px *end)
{
	clip_bgn_left(img, bgn, end);
	return (1);
}

const int		l12(t_img *img, t_px *bgn, t_px *end)
{
	clip_bgn_left(img, bgn, end);
	clip_end_right(img, bgn, end);
	return (1);
}

const int		l14(t_img *img, t_px *bgn, t_px *end)
{
	clip_bgn_left(img, bgn, end);
	if (bgn->y - end->y == 0)
		bgn->y = img->height - 2;
	clip_end_bottom(img, bgn, end);
	if (bgn->y > img->height - 2)
		return (0);
	return (1);
}
