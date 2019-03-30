/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 21:16:31 by ahugh             #+#    #+#             */
/*   Updated: 2019/03/29 14:31:17 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_img				*get_new_img(void *mlx, int width, int height)
{
	t_img			*img;
	int				bpp;
	int				endian;

	if (!(img = malloc(sizeof(t_img))))
		return (0);
	img->mlx = mlx;
	img->img = mlx_new_image(mlx, width, height);
	img->addr = mlx_get_data_addr(img->img, &bpp, &img->size, &endian);
	img->pos.x = 0;
	img->pos.y = 0;
	img->pos.color = 0;
	img->width = width;
	img->height = height;
	return (img);
}

static inline void	img_fill(t_img *img, size_t filler)
{
	register long	i;
	int				k;

	i = (img->height * img->width * 4) / 8;
	k = (img->height * img->width * 4) % 8;
	while (i > 0)
	{
		*((size_t*)img->addr + i) = filler;
		i--;
	}
	*((int*)img->addr + i * 2 + k) = (int)filler;
}

void				img_refresh(t_va *vault)
{
	if (apply_mods(vault->win, vault->source, &vault->tmp, &vault->mods))
		del_vault(vault);
	if (vault->mods.shleif == -1)
		img_fill(vault->img, BLACK);
	else
		img_fill(vault->img, BLACK_10);
	matrix_to_img(&vault->tmp, vault->img);
	mlx_put_image_to_window(vault->mlx, vault->win->win, vault->img->img,\
										vault->img->pos.x, vault->img->pos.y);
	print_help(vault);
}

void				del_img(t_img *img)
{
	if (img)
	{
		mlx_destroy_image(img->mlx, img->img);
		if (img->addr)
			free(img->addr);
		free(img);
		img = NULL;
	}
}

int					img_pixel_put(t_img *img, int x, int y, int color)
{
	((int*)img->addr)[img->width * y + x] = color;
	return (color);
}
