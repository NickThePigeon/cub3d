# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nduijf <nduijf@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/24 11:56:49 by nduijf        #+#    #+#                  #
#    Updated: 2021/10/12 16:28:34 by nduijf        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME 		=	libft.a
SRCS 		=	ft_bzero.c		\
				ft_isascii.c	\
				ft_memccpy.c	\
				ft_memcpy.c		\
				ft_strchr.c		\
				ft_strrchr.c	\
				ft_isalnum.c	\
				ft_isdigit.c	\
				ft_memchr.c		\
				ft_memmove.c	\
				ft_strlcat.c	\
				ft_strlen.c		\
				ft_strncmp.c	\
				ft_tolower.c	\
				ft_isalpha.c	\
				ft_isprint.c	\
				ft_memcmp.c		\
				ft_strcpy.c		\
				ft_strlcpy.c	\
				ft_strnstr.c	\
				ft_toupper.c	\
				ft_strdup.c		\
				ft_calloc.c		\
				ft_memset.c		\
				ft_putchar_fd.c \
				ft_strjoin.c 	\
				ft_putstr_fd.c	\
				ft_putendl_fd.c \
				ft_putnbr_fd.c 	\
				ft_substr.c 	\
				ft_strtrim.c 	\
				ft_itoa.c 		\
				ft_atoi.c		\
				ft_strmapi.c 	\
				ft_split.c 		\
				ft_freearr.c	\
				ft_read_to_eof.c	\
				ft_strstr.c		\
				ft_isspace.c	\
				loop_ft_is.c	\
				ft_namecheck.c	\
				ft_strduplen.c	\
				ft_arrlen.c		\
				ft_strjoin_free_s1.c \



OBJS		=	$(SRCS:.c=.o)

BONUS		=	ft_lstnew.c 	\
				ft_lstadd_front.c \
				ft_lstsize.c	\
				ft_lstlast.c 	\
				ft_lstadd_back.c \
				ft_lstdelone.c	\
				ft_lstclear.c	\
				ft_lstiter.c 	\

BONUS_OBJS	=	$(BONUS:.c=.o)
LIBC		=	ar -rcs
RM			=	rm -f
CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra
INCS		=	.
all:		$(NAME)
$(NAME):	$(OBJS)
			${LIBC} $(NAME) $(OBJS)
.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}
clean:
			${RM} $(OBJS) $(BONUS_OBJS)
fclean:		clean
			${RM} $(NAME)
re:			fclean all

bonus:		$(OBJS) $(BONUS_OBJS)
			ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
.PHONY:		all .c.o clean fclean re bonus
