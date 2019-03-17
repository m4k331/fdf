/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 18:20:25 by djon-con          #+#    #+#             */
/*   Updated: 2019/03/12 19:20:17 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	ft_exit(int i)
{
	if (i == 1)
		ft_putstr("Wrong input file.\n");
	else
		perror(NULL);
	exit(0);
}

/*
*	data[y*width + x]
*/

size_t	get_arr_max_size(const char *str, int *file_width)
{
	int		fd;
	size_t	i;
	int		gnl;
	char	*line;

	i = 0;
	*line = NULL;
	if ((fd = open(str, O_RDONLY)) == -1)
		ft_exit(0);
	while ((gnl = get_next_line(fd, &line)))
	{
		if (gnl == -1)
			ft_exit(0);
		i += ft_wc(line, ' ');
		(*file_width)++;
	}
	*file_width = i / *file_width;
	if (i == 0)
	{
		ft_putstr("File is empty.\n");
		exit(0);
	}
	close(fd);
	return (i);
}

void	fill_matrix(int fd, char *line, int *matrix, size_t file_width)
{
	size_t	arg_num;
	int		gnl;

	while ((gnl = get_next_line(fd, &line)) != 0)
	{
		if (gnl == -1)
			ft_exit(3);
		arg_num = 0;
		while (*line)
		{
			if (*line >= '0' && *line <= '9')
			{
				*(matrix++) = atoi_move(&line);
				arg_num++;
			}
			else if (*line == ' ')
				while (*line == ' ')
					line++;
			else
				ft_exit(1);
		}
		if (arg_num != file_width)
			ft_exit(1);
	}
}

/*
*	matrix->data[y + 1][x]	---> matrix->data[matrix->width * y + x]
*	DATA(y, x)				---> matrix->data[matrix->width * y + x]
*/

t_matrix	*parse(const char *file)
{
	t_matrix	*matrix;
	int			fd;

	if (!(matrix = malloc(sizeof(t_matrix))))
		ft_exit(0);
	matrix->width = 0;
	matrix->len = get_arr_max_size(file, &matrix->width);
	if (!(matrix->data = malloc(sizeof(int) * (matrix->len))))
		ft_exit(0);
	fd = open(file, O_RDONLY);
	fill_matrix(fd, NULL, matrix->data, matrix->width);
	print_int_arr(matrix->data, matrix->len);
	return (matrix);
}

int	main(void)
{
	t_matrix *tmp;

	tmp = parse("42.fdf");
}
