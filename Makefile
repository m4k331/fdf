# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahugh <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 18:51:35 by ahugh             #+#    #+#              #
#    Updated: 2019/03/13 13:44:14 by ahugh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	aa

FILES			=	main.c \
					draw_line.c \
					utils_draw_line.c \
					px.c \
					color.c \
					image.c \
					window.c

DIR_MLX			=	minilibx_macos

LIB_MLX			=	-lmlx

LIB_FT			=	libft.a

LIB_DIR			=	libft

FRAMEWORKS		=	-framework OpenGL -framework Appkit

FLAGS			=	 -I $(DIR_MLX) -L $(DIR_MLX) $(LIB_MLX) \
					 $(LIB_DIR)/$(LIB_FT) $(FRAMEWORKS)

CC				=	gcc


all: $(NAME)

$(NAME):
				@$(MAKE) -C $(LIB_DIR)
				@$(CC) $(FLAGS) $(FILES) -o $(NAME)

clean:
				@$(MAKE) -C $(LIB_DIR) fclean
				@rm -f $(NAME)

re: clean all
