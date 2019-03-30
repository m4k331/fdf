/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:27:51 by djon-con          #+#    #+#             */
/*   Updated: 2019/03/28 21:08:00 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_win			*get_new_win(void *mlx, int width, int height, char *name)
{
	t_win		*window;

	if (!(window = malloc(sizeof(t_win))))
		return (0);
	window->mlx = mlx;
	if (!(window->win = mlx_new_window(mlx, width, height, name)))
		free(window);
	else
	{
		window->width = width;
		window->height = height;
		window->name = name;
	}
	return (window);
}

void			del_vault(t_va *vault)
{
	del_matrix(vault->source);
	del_img(vault->img);
	mlx_destroy_window(vault->win->mlx, vault->win->win);
	if (vault->mlx)
		free(vault->mlx);
}
