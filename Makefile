# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nicky <nicky@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/02/18 16:22:27 by nicky         #+#    #+#                  #
#    Updated: 2022/10/16 12:51:19 by nicky         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =				cub3D
SRCS = 				src/cub3d.c \
					src/pixel_put.c \
					src/parse_map.c \
					src/exit.c \
					src/keys.c \
					src/checks.c \
					src/draw_screen.c \
					src/parse_strings.c \
					src/parse_tools.c \
					src/parse.c \
					src/tex.c \
					src/raycasting.c \

OBJS			= $(SRCS:.c=.o)

HEADER_FILE		= cub3d.h
CFLAGS			= -Wall -Wextra -Werror -I./includes/
LIBFT			= libft/libft.a
LIBS			= -LMLX42 -framework OpenGL -framework AppKit -lm
CC				= gcc
MLX				= libmlx42.a
# MLX				= libmlx.dylib

all:	$(NAME)

$(NAME): $(LIBFT) $(OBJS) $(MLX)
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT} ${MLX}

$(LIBFT):
	make -C libft

$(MLX):
	@$(MAKE) -C MLX42
	@mv MLX42/$(MLX) .

clean:
	make clean -C libft
	@$(MAKE) -C MLX42 clean
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME) $(LIBFT) $(MLX)

re:	fclean $(NAME)

.PHONY: all clean fclean re
