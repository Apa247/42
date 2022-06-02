# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/02 20:33:38 by daparici          #+#    #+#              #
#    Updated: 2022/06/02 20:53:50 by daparici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = fractol
CC = gcc 
CFLAGS = -Wall -Werror -Wextra

SRCS = fractol.c

OBJS = ${SRCS:.c=.o}

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
all: $(NAME)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME) 
re: clean all
.PHONY: bonus all clean fclean re

