/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 16:54:42 by ahugh             #+#    #+#             */
/*   Updated: 2019/03/17 20:29:35 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

#define IS_NEGATIVE(x, y) ((x) < 0 || (y) < 0)
#define IS_OVER(x, y, xe, ye) ((x) > (xe) || (y) > (ye))

int					is_steep_line(t_px *bgn, t_px *end)
{
	int				steep;

	steep = 0;
	if (end->x - bgn->x < ABS(end->y - bgn->y))
	{
		ft_swap32((uint32_t*)&bgn->x, (uint32_t*)&bgn->y);
		ft_swap32((uint32_t*)&end->x, (uint32_t*)&end->y);
		steep = 1;
	}
	return (steep);
}

static inline void	fix_bgn_coord(t_img *img, t_px *bgn, t_px *end)
{
	int				dx;
	int				dy;
	int				x;
	int				y;

	x = ABS(end->x - bgn->x);
	y = ABS(end->y - bgn->y);
	dx = x - ABS(bgn->x);
	dy = y - (int)((float)(ABS(bgn->x) / (float)x) * y + 0.5);
	bgn->x = end->x - dx;
	bgn->y = (bgn->y < end->y ? end->y - dy : end->y + dy);
}

static inline void	fix_end_coord(t_img *img, t_px *bgn, t_px *end)
{

}

int					fix_coords_beyond_img(t_img *img, t_px *bgn, t_px *end)
{
	int				xe;
	int				ye;

	xe = img->width - 1;
	ye = img->height - 2;
	printf("bgn[%d,%d]\tend[%d,%d]\t", bgn->x, bgn->y, end->x, end->y);
	if ((IS_OVER(bgn->x, bgn->y, xe, ye) && IS_OVER(end->x, end->y, xe, ye)) || 
			(IS_NEGATIVE(bgn->x, bgn->y) && IS_NEGATIVE(end->x, end->y)))
	{
		printf("DD\n");
		return (0);
	}
	if (IS_NEGATIVE(bgn->x, bgn->y) || IS_NEGATIVE(end->x, end->y))
		fix_bgn_coord(img, bgn, end);
	if (IS_OVER(end->x, end->y, xe, ye))
		fix_end_coord(img, bgn, end);
	return (1);
}
