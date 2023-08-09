# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 14:19:07 by zael-wad          #+#    #+#              #
#    Updated: 2023/08/04 22:47:00 by zael-wad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -fsanitize=address -g3 #-Wall -Wextra -Werror
SRCS = main.c ft_split.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\
		help_functions.c\
		map2d.c\
		player_movmentes.c\
		rotation.c\
		rander_map.c\

OBJ = $(SRCS:.c=.o)
NAME = cub3d

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Imlx -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all