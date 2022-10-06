# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saguesse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 14:54:21 by saguesse          #+#    #+#              #
#    Updated: 2022/10/04 16:25:40 by saguesse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc -g3

CFLAGS = -Wall -Werror -Wextra

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

PRINTF_PATH = ./libft/ft_printf

PRINTF = $(PRINTF_PATH)/libftprintf.a

MLX_PATH = ./mlx_linux

MLX = $(MLX_PATH)/libmlx.a

SRC = main.c \
	parsing.c \
	window.c \
	drawing.c \
	bresenham.c \
	hook.c \
	color.c \

HEADER = fdf.h

HEADER_LIBFT = $(LIBFT_PATH)/libft.h

HEADER_PRINTF = $(PRINTF_PATH)/libftprintf.h

MLX_HEADER = $(MLX_PATH)/mlx.h

OBJ = $(SRC:.c=.o)

$(NAME): $(MLX) $(PRINTF) $(LIBFT) $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(MLX) -L/usr/lib -lXext -lX11 -lm

$(LIBFT):
	make -C $(LIBFT_PATH)

$(PRINTF):
	make -C $(PRINTF_PATH)

%.o : %.c $(HEADER) $(HEADER_LIBFT) $(HEADER_PRINTF) $(HEADER_MLX)
	$(CC) $(CFLAGS) -c $< -o $@ -I . -I libft -I libft/ft_printf -I mlx_linux -I/usr/include

all: $(NAME) 

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re
