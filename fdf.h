/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:21:07 by djon-con          #+#    #+#             */
/*   Updated: 2019/03/12 18:32:01 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
#define	FDF_H

# define X_WINDOW_RES 1000
# define Y_WINDOW_RES 1000
# define DATA(y, x) matrix->data[matrix->width * (y) + (x)]
# define ABS(x) x > 0 ? x : -x

#include "mlx.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include "libft/includes/libft.h"

typedef struct	s_dot
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_dot;

typedef struct	s_win
{
	void		*ptr;
	void		*window;
	int			x;
	int			y;
}				t_win;

typedef struct	s_matrix
{
	int			*data;
	int			width;
	int			len;
}				t_matrix;

typedef struct	s_img
{
	void		*img;
	void		*mlx;
	void		*addr;
	int			width;
	int			height;
}				t_img;

typedef struct	s_px
{
	int			x;
	int			y;
	int			color;
}				t_px;

void			draw_line(t_win *mlx, t_dot *start, t_dot *end);

#endif
