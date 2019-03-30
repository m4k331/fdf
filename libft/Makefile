# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahugh <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 18:51:35 by ahugh             #+#    #+#              #
#    Updated: 2019/03/15 17:05:28 by djon-con         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a

# directories

SRC_DIR			=	srcs
INC_DIR			=	includes

# sub directories

MEM_DIR			=	memory
PRT_DIR			=	print
STR_DIR			=	string
LST_DIR			=	list
UTL_DIR			=	utils
VEC_DIR			=	vector
DJC_DIR			=	djon-con

# files

MEM				=	ft_bzero.c \
					ft_memccpy.c \
					ft_memcmp.c \
					ft_memdel.c \
					ft_memset.c \
					ft_memalloc.c \
					ft_memchr.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_memswap.c

PRT				=	ft_putchar.c \
					ft_putchar_fd.c \
					ft_putendl.c \
					ft_putendl_fd.c \
					ft_putnbr.c \
					ft_putnbr_fd.c

STR				=	ft_putstr.c \
					ft_strcmp.c \
					ft_striter.c \
					ft_strmap.c \
					ft_strnequ.c \
					ft_strstr.c \
					ft_putstr_fd.c \
					ft_strcpy.c \
					ft_striteri.c \
					ft_strmapi.c \
					ft_strnew.c \
					ft_strsub.c \
					ft_strcat.c \
					ft_strdel.c \
					ft_strjoin.c \
					ft_strncat.c \
					ft_strnstr.c \
					ft_strtrim.c \
					ft_strchr.c \
					ft_strdup.c \
					ft_strlcat.c \
					ft_strncmp.c \
					ft_strrchr.c \
					ft_wc.c \
					ft_strclr.c \
					ft_strequ.c \
					ft_strlen.c \
					ft_strncpy.c \
					ft_strsplit.c

LST				=	ft_lstadd.c \
					ft_lstaddlast.c \
					ft_lstdel.c \
					ft_lstdelone.c \
					ft_lstiter.c \
					ft_lstmap.c \
					ft_lstnew.c \
					ft_lstdelnbr.c \
					ft_lstdellast.c \
					ft_lstrev.c \
					ft_lstjoin.c \
					ft_lstlast.c \
					ft_lstcreate.c \
					ft_lstat.c \
					ft_lstsize.c \
					ft_lstrm.c

DJC				=	atoi_move.c \
					print_int_arr.c \
					ft_realloc.c	\
					get_next_line.c \
					ft_atoi_hex.c

UTL				=	ft_arrdel.c \
					ft_isalnum.c \
					ft_isascii.c \
					ft_isprint.c \
					ft_itoa.c \
					ft_toupper.c \
					ft_atoi.c \
					ft_isalpha.c \
					ft_isdigit.c \
					ft_isspace.c \
					ft_tolower.c \
					ft_swap.c

VEC				=	ft_verase.c \
					ft_vnew.c \
					ft_vresize.c \
					ft_vpush_back.c \
					ft_vat.c \
					ft_vmax_size.c \
					ft_vsize.c \
					ft_vpop_back.c \
					ft_vcapacity.c \
					ft_vreserve.c \
					ft_vreadfile.c \
					ft_vunused_size.c

FILES			+=	$(MEM) \
					$(PRT) \
					$(STR) \
					$(LST) \
					$(UTL) \
					$(VEC) \
					$(DJC)

OBJ				=	$(FILES:%.c=%.o)

# exceptions

.PHONY:				all clean fclean re

# flags

FLAGS			=	-Wextra -Wall -Werror -I./$(INC_DIR)/ -c
CC				=	gcc

# rules

all: $(NAME)

$(NAME):
				@$(CC) $(FLAGS) \
					$(addprefix ./$(SRC_DIR)/$(MEM_DIR)/, $(MEM)) \
					$(addprefix ./$(SRC_DIR)/$(PRT_DIR)/, $(PRT)) \
					$(addprefix ./$(SRC_DIR)/$(STR_DIR)/, $(STR)) \
					$(addprefix ./$(SRC_DIR)/$(LST_DIR)/, $(LST)) \
					$(addprefix ./$(SRC_DIR)/$(UTL_DIR)/, $(UTL)) \
					$(addprefix ./$(SRC_DIR)/$(VEC_DIR)/, $(VEC)) \
					$(addprefix ./$(SRC_DIR)/$(DJC_DIR)/, $(DJC))
				@ar rc $(NAME) $(OBJ)
				@ranlib $(NAME)

%.o: %.c
				@$(CC) $(FLAGS) $< -o $@

clean:
				@rm -f $(OBJ)

fclean: clean
				@rm -f $(NAME)

re: fclean all
