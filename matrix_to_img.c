/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_to_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 20:41:47 by djon-con          #+#    #+#             */
/*   Updated: 2019/03/28 20:36:37 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void				matrix_to_img(t_matrix *tmp, t_img *img)
{
	t_dot			*data;
	register int	i;
	int				max;

	i = 0;
	max = tmp->len - 1;
	data = (t_dot*)tmp->data;
	while (i < max)
	{
		if ((i + 1) % tmp->width == 0)
		{
			if (i + 1 != tmp->len)
				draw_line_smoothing(img, *(t_px*)(data + i),\
						*(t_px*)(data + i + tmp->width));
			i++;
		}
		draw_line_smoothing(img, *(t_px*)(data + i), *(t_px*)(data + i + 1));
		if (i < tmp->len - tmp->width)
			draw_line_smoothing(img, *(t_px*)(data + i),\
					*(t_px*)(data + i + tmp->width));
		i++;
	}
}
