# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 12:38:29 by daparici          #+#    #+#              #
#    Updated: 2022/06/24 17:07:53 by daparici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = So_long
CC = gcc 
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs

SRCS = so_long.c check_map_1.c check_map_2.c game.c
GNL = get_next_line.c get_next_line_utils.c
GNLPATH = $(addprefix ./GetNextLine/,$(GNL))
LIBFT = ./Libft/libft.a

OBJS = ${SRCS:.c=.o}
GNLOBJ = $(GNLPATH:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS) $(GNLOBJ)
		make bonus -C ./Libft;
#		$(CC) $(CFLAGS) $(OBJS) $(GNLOBJ) $(LIBFT) -L ./Libft -l ft -o -lmlx -framework OpenGL -framework AppKit -o $(NAME)
		$(CC) $(CFLAGS) $(OBJS) $(GNLOBJ) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
all: $(NAME)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME) 
re: clean all
.PHONY: bonus all clean fclean re