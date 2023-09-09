# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 14:19:07 by zael-wad          #+#    #+#              #
#    Updated: 2023/09/04 11:23:48 by zael-wad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -fsanitize=address -g3 #-Wall -Wextra -Werror
SRCS = 	main.c\
		player_movmentes.c\
		help_functions.c\
		rotation.c\
		rander_map.c\
		virtical_ray.c\
		horizontal_ray.c\
		parsing/parsing.c\
		parsing/Libft/ft_strcmp.c\
		parsing/Libft/ft_strchr.c\
		parsing/get_next_line/get_next_line.c\
		parsing/Libft/ft_strjoin.c\
		parsing/Libft/ft_substr.c\
		parsing/Libft/ft_split.c \
		parsing/Libft/ft_putstr_fd.c\
		parsing/Libft/ft_strtrim.c\
		parsing/Libft/ft_strncmp.c\
		parsing/Libft/ft_isdigit.c\
		parsing/Libft/ft_atoi.c\
		parsing/get_next_line/get_next_line_utils.c\
		parsing/Parsing/map_validation.c\
		parsing/Parsing/ft_lstnew_s.c\
		parsing/Parsing/ft_lstadd_back_s.c\
		parsing/Parsing/map_processing.c\
		parsing/Parsing/ft_errors.c\
		parsing/Parsing/player.c\
		parsing/Parsing/check_colors.c\
		parsing/Parsing/check_spaces.c\

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