/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 20:52:01 by ahugh             #+#    #+#             */
/*   Updated: 2019/03/29 15:57:48 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static inline void	init_hook(t_va *vault)
{
	mlx_hook(vault->win->win, 2, 0, press_key, vault);
	mlx_hook(vault->win->win, 6, 0, mouse_move, vault);
	mlx_hook(vault->win->win, 17, 0, red_close, vault);
	mlx_mouse_hook(vault->win->win, mouse_press, vault);
	mlx_hook(vault->win->win, 5, 0, mouse_release, vault);
}

static inline void	exit_free(void *p1, void *p2)
{
	if (p1)
		free(p1);
	if (p2)
		free(p2);
	ft_exit(0);
}

static inline void	init_vault(t_va *vault, char *url)
{
	int				half_width;

	half_width = 0;
	set_mods(vault);
	vault->mlx = mlx_init();
	parse(url, vault);
	if (!(vault->win = get_new_win(vault->mlx, W, H, "FDF")))
		exit_free(vault->mlx, NULL);
	if (!(vault->img = get_new_img(vault->mlx, W, H)))
	{
		mlx_destroy_window(vault->win->mlx, vault->win->win);
		exit_free(vault->mlx, NULL);
	}
	if (!(vault->tmp.data = malloc(sizeof(t_dot) * vault->source->len)))
	{
		mlx_destroy_window(vault->win->mlx, vault->win->win);
		exit_free(vault->mlx, vault->img);
	}
	half_width = vault->source->width;
	vault->mods.resize_offset.x = -1 * half_width / 2;
	vault->mods.resize_offset.y = -1 * vault->source->len / half_width / 2;
}

int					main(int ac, char **av)
{
	t_va			vault;

	ft_bzero(&vault, sizeof(t_va));
	if (ac > 1)
	{
		init_vault(&vault, av[1]);
		if (apply_mods(vault.win, vault.source, &vault.tmp, &vault.mods))
			del_vault(&vault);
		matrix_to_img(&vault.tmp, vault.img);
		img_refresh(&vault);
		init_hook(&vault);
		mlx_loop(vault.mlx);
	}
	else
		ft_putstr_fd("usage: fdf source_map\n", 2);
	return (0);
}
