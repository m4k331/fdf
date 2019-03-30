/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 18:20:25 by djon-con          #+#    #+#             */
/*   Updated: 2019/03/29 15:46:40 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static size_t		get_arr_max_size(const char *str, int *file_width)
{
	size_t			i;
	int				fd;
	int				gnl;
	char			*line;

	i = 0;
	line = NULL;
	if ((fd = open(str, O_RDONLY)) == -1)
		ft_exit(0);
	while ((gnl = get_next_line(fd, &line)))
	{
		if (gnl == -1)
			ft_exit(0);
		i += ft_wc(line, ' ');
		(*file_width)++;
		free(line);
	}
	*file_width = i / *file_width;
	if (i == 0)
	{
		ft_putstr_fd("File is empty.\n", 2);
		exit(1);
	}
	close(fd);
	return (i);
}

static inline void	line_to_coords(t_dot *dot, char **line, \
												size_t *arg_num, t_dot *coord)
{
	while (**line)
	{
		if (**line >= '0' && **line <= '9')
		{
			dot->x = (*coord).x++;
			dot->y = (*coord).y;
			dot->z = atoi_move(line);
			if (dot->z > coord->z)
				coord->z = dot->z;
			dot->color = 0xffffff;
			if (**line == ',')
			{
				(*line)++;
				dot->color = ft_atoi_move_hex(line);
			}
			dot++;
			(*arg_num)++;
		}
		else if (**line == ' ')
			while (**line == ' ')
				(*line)++;
		else
			ft_exit(1);
	}
}

static inline void	fill_matrix(int fd, t_dot *dot, size_t file_width)
{
	t_dot			coord;
	char			*line;
	char			*tofree;
	size_t			arg_num;
	int				gnl;

	coord.y = 0;
	coord.z = 0;
	while ((gnl = get_next_line(fd, &line)) != 0)
	{
		tofree = line;
		if (gnl == -1)
			ft_exit(0);
		arg_num = 0;
		coord.x = 0;
		line_to_coords(dot + coord.y * file_width, &line, &arg_num, &coord);
		free(tofree);
		if (arg_num != file_width)
			ft_exit(1);
		coord.y++;
	}
}

void				del_matrix(t_matrix *matrix)
{
	if (matrix)
	{
		if (matrix->data)
			free(matrix->data);
		free(matrix);
	}
	ft_exit(42);
}

void				parse(const char *file, t_va *vault)
{
	t_matrix		*matrix;
	int				fd;

	if (!(matrix = malloc(sizeof(t_matrix))))
		ft_exit(0);
	matrix->width = 0;
	matrix->len = get_arr_max_size(file, &matrix->width);
	if (!(matrix->data = malloc(sizeof(t_dot) * (matrix->len))))
		del_matrix(matrix);
	if ((fd = open(file, O_RDONLY)) == -1)
		del_matrix(matrix);
	fill_matrix(fd, matrix->data, matrix->width);
	if (close(fd) == -1)
		del_matrix(matrix);
	vault->source = matrix;
}
