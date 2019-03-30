/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 22:54:20 by ahugh             #+#    #+#             */
/*   Updated: 2019/03/29 15:18:11 by djon-con         ###   ########.fr       */
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

# define W			1500
# define H 			1500
# define OFFSET_X	700
# define OFFSET_Y	700
# define PERSP_DIST	1200.0
# define ROT_SPEED	5
# define COLOR		0x00ff00
# define BLACK		0
# define BLACK_10	0xF2000000F2000000ULL
# define X_RAD		(rotation.x * M_PI / 180)
# define Y_RAD		(rotation.y * M_PI / 180)
# define Z_RAD		(rotation.z * M_PI / 180)
# define ABS(x)		((x) < 0 ? -1 * (x) : (x))
# define SCALE		30
# define MIN_SCALE	2
# define MAX_SCALE	1000
# define ZOOM		1
# define ABS(x)		((x) < 0 ? -1 * (x) : (x))
# define FPX(x)		(float)((float)1.0 - ((float)(x) - (int)(x)))
# define SPX(x)		(float)((float)(x) - (int)(x))
# define NEGATIVE(x, y) ((x) < 0 || (y) < 0)
# define OVER(x, y, x_over, y_over) ((x) > (x_over) || (y) > (y_over))
# define GREEN 		0x32CD32
# define GOLD		0xFFD700
# define YELLOW		0xFFFF00
# define ORANGE		0xFFA500
# define SALMON		0xFA8072
# define CRIMSON	0x800000
# define KHAKI		0xF0E68C
# define ORCHID		0x9932CC
# define RO_BLUE	0x4169E1
# define PINK		0xFF1493
# define SKY		0x87CEFA
# define AQUA		0x7FFFD4

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

/*
** ############################## MODIFIERS ###################################
*/

typedef	enum	e_proj
{
	ISOMETRIC,
	PERSPECTIVE,
	PARALLEL
}				t_proj;

typedef	struct	s_dot
{
	int			x;
	int			y;
	int			color;
	int			z;
}				t_dot;

typedef struct	s_mod
{
	int			colorize;
	int			persp_dist;
	int			shleif;
	int			scale;
	float		height;
	t_dot		rotation;
	t_proj		projection;
	t_px		offset;
	t_px		resize_offset;
}				t_mod;

/*
** ################################ IMG #######################################
*/

typedef struct	s_img
{
	void		*mlx;
	void		*img;
	void		*addr;
	t_px		pos;
	int			size;
	int			width;
	int			height;
}				t_img;

void			img_clear(t_img *img);
void			del_img(t_img *img);
t_img			*get_new_img(void *mlx, int width, int height);
int				img_pixel_put(t_img *img, int x, int y, int color);

/*
** ################################ WIN #######################################
*/

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	char		*name;
	int			width;
	int			height;
}				t_win;

void			put_img_to_win(t_win *win, t_img *img, t_px pos);
void			del_win(t_win *win);
t_win			*get_new_win(void *mlx, int width, int height, char *name);

/*
** ################################# KEY ######################################
*/

typedef struct	s_mouse
{
	t_px		start;
	int			move;
}				t_mouse;

int				red_close(void *param);
int				mouse_move(int x, int y, void *param);
int				mouse_press(int key, int x, int y, void *param);

/*
** ################################## MATRIX ##################################
*/

typedef struct	s_matrix
{
	t_dot		*data;
	int			width;
	int			len;
}				t_matrix;

int				apply_mods(t_win *win, t_matrix *source, \
													t_matrix *tmp, t_mod *mods);
void			del_matrix(t_matrix *matrix);

/*
** ################################ UTILS #####################################
*/

void			ft_exit(int a);
void			swap_coords(t_px **bgn, t_px **end);
void			draw_straight_line(t_img *img, t_px *bgn, t_px *end);
void			draw_slant_line(t_img *img, t_px *bgn, t_px *end);
int				draw_line_smoothing(t_img *img, t_px bgn, t_px end);
int				get_code_px(t_img *img, t_px *px);

/*
** ############################### COLOR ######################################
*/

int				get_color_v(t_px *bgn, t_px *end, int pos, float transparency);
int				get_color_h(t_px *bgn, t_px *end, int pos, float transparency);
int				set_transparency(int color, float transparency);

/*
** ############################### MAIN #######################################
*/

typedef struct	s_va
{
	void		*mlx;
	t_win		*win;
	t_img		*img;
	t_matrix	*source;
	t_mouse		mouse;
	t_mod		mods;
	t_matrix	tmp;
}				t_va;

int				press_key(int key, void *mods);
int				move_map(int key, t_va *vault);
int				mouse_release(int button, int x, int y, void *param);
int				mouse_move(int x, int y, void *param);
int				mouse_press(int key, int x, int y, void *param);

int				draw_line(t_img *img, t_px *bgn, t_px *end);

void			parse(const char *file, t_va *vault);
void			apply_projection(t_dot *dot, t_mod *mods);
void			del_vault(t_va *vault);

void			matrix_to_img(t_matrix *tmp, t_img *img);
int				change_scale(int key, void *vault);
void			img_refresh(t_va *vault);
void			set_mods(t_va *vault);
void			apply_resize(t_dot *dot, int scale);
void			apply_offset(t_dot *dot, t_px coords);
void			apply_rotation(t_dot *dot, t_dot rotation);
void			apply_color(t_dot *dot);
void			apply_height(t_dot *dot, float height);
int				color_log(int z);
int				rotate(int key, t_dot *rot);
void			change_height(int key, float *height);
void			change_rotation(t_dot *rotation, int x, int y, int z);
void			change_perspective_dist(int key, int *dist);
void			ft_reset(t_mod *mods);
void			print_help(t_va *vault);

/*
** ################################## Clipping ################################
*/

int				fc_line(t_img *img, t_px *bgn, t_px *end);

void			clip_bgn_top(t_img *img, t_px *bgn, t_px *end);
void			clip_bgn_bottom(t_img *img, t_px *bgn, t_px *end);
void			clip_bgn_right(t_img *img, t_px *bgn, t_px *end);
void			clip_bgn_left(t_img *img, t_px *bgn, t_px *end);

void			clip_end_top(t_img *img, t_px *bgn, t_px *end);
void			clip_end_bottom(t_img *img, t_px *bgn, t_px *end);
void			clip_end_right(t_img *img, t_px *bgn, t_px *end);
void			clip_end_left(t_img *img, t_px *bgn, t_px *end);

const int		c0(t_img *img, t_px *bgn, t_px *end);
const int		c2(t_img *img, t_px *bgn, t_px *end);
const int		c4(t_img *img, t_px *bgn, t_px *end);
const int		c6(t_img *img, t_px *bgn, t_px *end);
const int		c8(t_img *img, t_px *bgn, t_px *end);
const int		ca(t_img *img, t_px *bgn, t_px *end);

const int		l10(t_img *img, t_px *bgn, t_px *end);
const int		l12(t_img *img, t_px *bgn, t_px *end);
const int		l14(t_img *img, t_px *bgn, t_px *end);
const int		l16(t_img *img, t_px *bgn, t_px *end);
const int		l18(t_img *img, t_px *bgn, t_px *end);
const int		l1a(t_img *img, t_px *bgn, t_px *end);

const int		lt90(t_img *img, t_px *bgn, t_px *end);
const int		lt92(t_img *img, t_px *bgn, t_px *end);
const int		lt94(t_img *img, t_px *bgn, t_px *end);
const int		lt96(t_img *img, t_px *bgn, t_px *end);

const int		lb50(t_img *img, t_px *bgn, t_px *end);
const int		lb52(t_img *img, t_px *bgn, t_px *end);
const int		lb58(t_img *img, t_px *bgn, t_px *end);
const int		lb5a(t_img *img, t_px *bgn, t_px *end);

const int		b40(t_img *img, t_px *bgn, t_px *end);
const int		b42(t_img *img, t_px *bgn, t_px *end);
const int		b48(t_img *img, t_px *bgn, t_px *end);
const int		b4a(t_img *img, t_px *bgn, t_px *end);

const int		t80(t_img *img, t_px *bgn, t_px *end);
const int		t82(t_img *img, t_px *bgn, t_px *end);
const int		t84(t_img *img, t_px *bgn, t_px *end);
const int		t86(t_img *img, t_px *bgn, t_px *end);

#endif
