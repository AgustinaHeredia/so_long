# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 11:45:19 by agheredi          #+#    #+#              #
#    Updated: 2023/10/02 13:40:34 by agheredi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
FLAGS = -Wall -Werror -Wextra --debug -g
SRC = so_long.c \
	 check_arg.c \
	 exit.c \
	 rules_map.c \
	 utils.c \
	 game_init.c \
	 key_press.c \
	 
CC = gcc
MLX_PATH = mlx/
MLX_LIB = $(MLX_PATH)libmlx.a
MLX_FLAGS = -Lmlx -lmlx -framework OPENGL -framework AppKit
LIBFT_PATH = libft/
LIBFT_LIB = $(LIBFT_PATH)libft.a
OBJECTS = $(SRC:.c=.o)
HEADER = so_long.h 

all: subsystems $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -Imlx -c -o $@ $<

subsystems:
	make -C $(MLX_PATH) all
	make -C $(LIBFT_PATH) all

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(MLX_FLAGS) $(OBJECTS) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)

clean:
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) clean
	rm -f *.o 

fclean: clean
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) fclean
	
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean subsystems
