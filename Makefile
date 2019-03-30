# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahugh <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 18:51:35 by ahugh             #+#    #+#              #
#    Updated: 2019/03/30 11:45:00 by ahugh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fdf

FILES			=	main.c \
					draw_line.c \
					utils_draw_line.c \
					color.c \
					image.c \
					parse.c \
					apply_mods.c \
					projection.c \
					matrix_to_img.c \
					exit.c \
					press_key.c \
					draw_straight_line.c \
					draw_slant_line.c \
					clip_bgn.c \
					clip_end.c \
					window.c \
					mouse_key.c \
					set_mods.c \
					mods.c \
					center_p1.c \
					center_p2.c \
					left_p1.c \
					left_p2.c \
					left_top.c \
					left_bottom.c \
					bottom.c \
					top.c \
					color_log.c \
					press_actions.c \
					print_help.c

DIR_MLX			=	minilibx_macos

LIB_MLX			=	-lmlx

LIB_FT			=	libft.a

LIB_DIR			=	libft

FRAMEWORKS		=	-framework OpenGL -framework Appkit

WWW				=	-Wall -Werror -Wextra

FLAGS			=	$(WWW) $(LIB_DIR)/$(LIB_FT) $(LIB_MLX) $(FRAMEWORKS)

HEADER			=	draw.h

CC				=	gcc

OBJ				= $(FILES:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
				@$(MAKE) -C $(LIB_DIR) >> /dev/null
				@$(CC) $(OBJ) -o $(NAME) $(FLAGS)

%.o: %.c $(HEADER)
				@$(CC) -c $< -o $@

clean:
				@rm -f *.o
				
fclean: clean
				@$(MAKE) -C $(LIB_DIR) fclean >> /dev/null
				@rm -f $(NAME)

re: fclean all
