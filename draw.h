/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 22:54:20 by ahugh             #+#    #+#             */
/*   Updated: 2019/03/17 23:00:59 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# include "libft/includes/libft.h"
# include "mlx.h"
# include "color.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

# define SCALE 10
# define ABS(x) ((x) < 0 ? -1 * (x) : (x))

/*
** ################################## PX ######################################
*/

typedef struct	s_px
{
	int			x;
	int			y;
	int			color;
}				t_px;

void			set_px(t_px *px, int x, int y, int color);
t_px			*get_px(int x, int y, int color);

/*
** ################################## MATRIX ##################################
*/

typedef struct	s_matrix
{
	int			*data;
	int			width;
	int			len;
}				t_matrix;

/*
** ################################ IMG #######################################
*/

typedef struct	s_img
{
	void		*mlx;
	void		*img;
	void		*addr;
	t_px		*pos;
	int			size;
	int			width;
	int			height;
	int			scale;
}				t_img;

void			clear_img(t_img *img);
void			destroy_img(t_img *img);
t_img			*get_new_img(void *mlx, int width, int height);
int				img_pixel_put(t_img *img, int x, int y, int color);

/*
** ################################ WIN #######################################
*/

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	t_img		**img;
	char		*name;
	int			img_count;
	int			width;
	int			height;
}				t_win;

void			put_img_to_win(t_win *win, t_img *img, t_px *pos);
void			destroy_win(t_win *win);
t_win			*get_new_win(void *mlx, int width, int height, char *name);

/*
** ################################# MAP ######################################
*/

/*
** ################################ UTILS #####################################
*/

int				is_steep_line(t_px *bgn, t_px *end);
int				fix_coords_beyond_img(t_img *img, t_px *bgn, t_px *end);

/*
** ############################### COLOR ######################################
*/

int				get_color(t_px *bgn, t_px *end, int pos, float transparency);

/*
** ############################### MAIN #######################################
*/

int				draw_line(t_img *img, t_px *bgn, t_px *end);
int				draw_line_smoothing(t_img *img, t_px *bgn, t_px *end);

#endif
