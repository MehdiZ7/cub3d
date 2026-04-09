# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/17 18:36:18 by mzouhir           #+#    #+#              #
#    Updated: 2026/04/09 12:39:40 by mzouhir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
SRCS =	main.c parsing/parse_map.c getnextline/get_next_line_utils.c getnextline/get_next_line.c \
		test_function.c parsing/parsing_utils.c parsing/parse_color.c parsing/parse_maze.c \
		parsing/check_maze.c parsing/floodfill.c raycasting/init_game.c raycasting/events.c \
		raycasting/init_player.c raycasting/raycasting.c raycasting/drawing.c raycasting/raycasting_utils.c \
		raycasting/events_move.c
OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
LIBFT_DIR = Libft
LIBFT = ${LIBFT_DIR}/libft.a
MLX_DIR = minilibx-linux
MLX = ${MLX_DIR}/libmlx_Linux.a
INCLUDES = -I${LIBFT_DIR} -I${MLX_DIR} -Iincludes
MLX_FLAGS = -lXext -lX11 -lm

all: ${LIBFT} ${MLX} ${NAME}

${LIBFT}:
	${MAKE} -C ${LIBFT_DIR}

${MLX}:
	${MAKE} -C ${MLX_DIR}

${NAME}: ${OBJS} ${LIBFT} ${MLX}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} ${MLX} ${MLX_FLAGS} -o ${NAME}

%.o: %.c
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

clean:
	rm -f ${OBJS}
	${MAKE} -C ${LIBFT_DIR} clean
	${MAKE} -C ${MLX_DIR} clean

fclean: clean
	rm -f ${NAME}
	${MAKE} -C ${LIBFT_DIR} fclean

re: fclean all

.PHONY: all clean fclean re


