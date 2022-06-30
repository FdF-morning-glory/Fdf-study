# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 17:01:08 by jinypark          #+#    #+#              #
#    Updated: 2022/06/21 16:20:06 by jinypark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = main

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft

SRCS = main.c

BONUS = main_bonus.c

OBJS_SRCS = $(SRCS:.c=.o)

OBJS_BONUS = $(BONUS:.c=.o)

ifdef BONUS_FLAG
	OBJS = $(OBJS_BONUS)
else
	OBJS = $(OBJS_SRCS)
endif

all: $(NAME)

%.o : %.c
	$(CC) -c -o $@ $<

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) -o main $(OBJS) -L ./minilibx_macos -lmlx -L ./libft -lft -g3 -fsanitize=address

bonus:
	make BONUS_FLAG=1 all

clean:
	make -C libft clean
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re:
	make fclean
	make all
# test: all

.PHONY: bonus all clean fclean re
