# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 14:19:07 by zael-wad          #+#    #+#              #
#    Updated: 2023/08/11 11:44:59 by zael-wad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -fsanitize=address -g3 #-Wall -Wextra -Werror
SRCS = main.c ft_split.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\
		help_functions.c\
		map2d.c\
		player_movmentes.c\
		rotation.c\
		rander_map.c\
		virtical_ray.c\
		horizontal_ray.c\
		rander_2dmap.c\

OBJ = $(SRCS:.c=.o)
NAME = cub3d

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	
%.o: %.c
	$(CC) -Imlx -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all