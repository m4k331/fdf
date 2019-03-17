/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 21:16:31 by ahugh             #+#    #+#             */
/*   Updated: 2019/03/13 15:21:53 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_img			*get_new_img(void *mlx, int width, int height)
{
	t_img		*img;
	int			bpp;
	int			endian;

	if (!(img = malloc(sizeof(t_img))))
		exit(0);
	img->mlx = mlx;
	img->img = mlx_new_image(mlx, width, height);
	img->addr = mlx_get_data_addr(img->img, &bpp, &img->size, &endian);
	img->pos = NULL;
	img->size /= 4;
	img->width = width;
	img->height = height;
	img->scale = SCALE;
	return (img);
}

void			clear_img(t_img *img)
{
	int			iter;

	iter = img->size;
	while (iter--)
		((int*)img->addr)[iter] = 0;
}

void			destroy_img(t_img *img)
{
	if (img)
	{
		mlx_destroy_image(img->mlx, img->img);
		if (img->addr)
			free(img->addr);
		if (img->pos)
			free(img->pos);
		free(img);
		img = NULL;
	}
}

int				img_pixel_put(t_img *img, int x, int y, int color)
{
	((int*)img->addr)[img->width * y + x] = color;
	return (color);
}
