/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 20:52:01 by ahugh             #+#    #+#             */
/*   Updated: 2019/03/17 22:42:21 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <stdio.h>

#define W 1500
#define H 1000

int				main(void)
{
	void		*mlx;
	t_win		*win;
	t_img		*img;
	t_px		*pos;
	t_px		*bgn;
	t_px		*end;

	mlx = mlx_init();
	win = get_new_win(mlx, W, H, "PRO100 T0P");
	img = get_new_img(mlx, W, H);
	pos = get_px(0, 0, 0);
//1
	bgn = get_px(100, 500, M_GN);
	end = get_px(500, 500, M_RD);
	draw_line_smoothing(img, bgn, end);
//2
	bgn = get_px(200, 400, M_GN);
	end = get_px(500, 500, M_RD);
	draw_line_smoothing(img, bgn, end);
//3	
	bgn = get_px(300, 300, M_GN);
	end = get_px(500, 500, M_RD);
	draw_line_smoothing(img, bgn, end);
//4	
	bgn = get_px(400, 200, M_GN);
	end = get_px(500, 500, M_RD);
	draw_line_smoothing(img, bgn, end);
//5	
	bgn = get_px(500, 100, M_GN);
	end = get_px(500, 500, M_RD);
	draw_line_smoothing(img, bgn, end);
	//6	
	bgn = get_px(600, 200, M_GN);
	end = get_px(500, 500, M_RD);
	draw_line_smoothing(img, bgn, end);
//7	
	bgn = get_px(700, 300, M_GN);
	end = get_px(500, 500, M_RD);
	draw_line_smoothing(img, bgn, end);
//8	
	bgn = get_px(800, 400, M_GN);
	end = get_px(500, 500, M_RD);
	draw_line_smoothing(img, bgn, end);
//9	
	bgn = get_px(900, 500, M_GN);
	end = get_px(500, 500, M_RD);
	draw_line_smoothing(img, bgn, end);
//10	
	bgn = get_px(800, 600, M_GN);
	end = get_px(500, 500, M_RD);
	draw_line_smoothing(img, bgn, end);
//11	
	bgn = get_px(700, 700, M_GN);
	end = get_px(500, 500, M_RD);
	draw_line_smoothing(img, bgn, end);
//12	
	bgn = get_px(600, 800, M_GN);
	end = get_px(500, 500, M_RD);
	draw_line_smoothing(img, bgn, end);
//13	
	bgn = get_px(500, 900, M_GN);
	end = get_px(500, 500, M_RD);
	draw_line_smoothing(img, bgn, end);
//14	
	bgn = get_px(400, 800, M_GN);
	end = get_px(500, 500, M_RD);
	draw_line_smoothing(img, bgn, end);
//15	
	bgn = get_px(300, 700, M_GN);
	end = get_px(500, 500, M_RD);
	draw_line_smoothing(img, bgn, end);
//16	
	bgn = get_px(200, 600, M_GN);
	end = get_px(500, 500, M_RD);
	draw_line_smoothing(img, bgn, end);

	put_img_to_win(win, img, pos);

	mlx_loop(win->mlx);
}
