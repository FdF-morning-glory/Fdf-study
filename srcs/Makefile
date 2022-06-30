# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 11:21:24 by sesim             #+#    #+#              #
#    Updated: 2022/06/30 13:31:56 by sesim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
RM = rm -f

SRCS = fdf.c \
	   isometric.c \
	   utils.c \
	   utils2.c \
	   draw.c \
	   ft_word_count.c

OBJS = $(SRCS:.c=.o)

NAME = fdf

all : $(NAME)

fdf: $(OBJS)
	$(CC) -g -L ../libft -l ft -L ./ -l mlx -framework OpenGL -framework AppKit $^ -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : fdf all clean fclean re
