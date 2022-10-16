# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nicky <nicky@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/02/18 16:22:27 by nicky         #+#    #+#                  #
#    Updated: 2022/10/16 16:06:57 by nicky         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# VPATH =				./mlx/
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
LIBS			= -Lmlx -framework OpenGL -framework AppKit -lm
CC				= gcc
MLX				= mlx/libmlx.a

all:	$(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT} ${MLX} ${LIBS}

$(LIBFT):
	make -C libft

$(MLX):
	@$(MAKE) -C mlx

clean:
	make clean -C libft
	make clean -C mlx
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME) $(LIBFT) $(MLX)

re:	fclean $(NAME)

.PHONY: all clean fclean re
