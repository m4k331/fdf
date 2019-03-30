/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_p2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 22:56:06 by ahugh             #+#    #+#             */
/*   Updated: 2019/03/27 22:56:49 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

const int		c0(t_img *img, t_px *bgn, t_px *end)
{
	return (img->width | bgn->x | end->x);
}

const int		c2(t_img *img, t_px *bgn, t_px *end)
{
	clip_end_right(img, bgn, end);
	return (1);
}

const int		c4(t_img *img, t_px *bgn, t_px *end)
{
	clip_end_bottom(img, bgn, end);
	return (1);
}
