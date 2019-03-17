/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:27:51 by djon-con          #+#    #+#             */
/*   Updated: 2019/03/13 15:21:58 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_win			*get_new_win(void *mlx, int width, int height, char *name)
{
	t_win		*window;

	if (!(window = malloc(sizeof(t_win))))
		exit(0);
	window->mlx = mlx;
	window->win = mlx_new_window(mlx, width, height, name);
	window->img_count = 0;
	window->width = width;
	window->height = height;
	window->name = name;
	window->img = NULL;
	return (window);
}

void			put_img_to_win(t_win *win, t_img *img, t_px *pos)
{
	t_img		**new_imgs;
	int			iter;

	img->pos = pos;
	iter = win->img_count++;
	if (!(new_imgs = (t_img**)malloc(sizeof(t_img*) * win->img_count)))
		exit(0);
	while (iter--)
		new_imgs[iter] = win->img[iter];
	free(win->img);
	win->img = new_imgs;
	win->img[win->img_count - 1] = img;
	mlx_put_image_to_window(win->mlx, win->win, img->img, pos->x, pos->y);
}

void			destroy_win(t_win *win)
{
	int			iter;

	iter = win->img_count;
	while (iter--)
		destroy_img(win->img[iter]);
	mlx_destroy_window(win->mlx, win->win);
	free(win);
	win = NULL;
}
