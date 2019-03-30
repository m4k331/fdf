/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_mods.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:38:07 by djon-con          #+#    #+#             */
/*   Updated: 2019/03/29 16:18:46 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static int	clone_matrix(t_matrix *tmp, t_matrix *source)
{
	tmp->width = source->width;
	tmp->len = source->len;
	ft_memmove(tmp->data, source->data, tmp->len * (sizeof(t_dot)));
	return (0);
}

int			apply_mods(t_win *win, t_matrix *source, t_matrix *tmp, t_mod *mods)
{
	t_dot	*dot;
	int		len;

	if (clone_matrix(tmp, source))
		return (1);
	dot = tmp->data;
	len = tmp->len;
	while (len--)
	{
		apply_height(dot, mods->height);
		if (mods->colorize == -1)
			apply_color(dot);
		apply_offset(dot, mods->resize_offset);
		apply_resize(dot, mods->scale);
		apply_rotation(dot, mods->rotation);
		apply_projection(dot, mods);
		apply_offset(dot, mods->offset);
		dot++;
	}
	return (0);
}
