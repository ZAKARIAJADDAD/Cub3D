# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 14:19:07 by zael-wad          #+#    #+#              #
#    Updated: 2023/09/12 21:55:25 by zael-wad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -fsanitize=address -g3 #-Wall -Wextra -Werror

LMLX_MAC = -Lmlx -lmlx -framework OpenGL -framework AppKit 
# LMLX_UNIX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
SRCS = 	main.c\
		mouse_move.c\
		filed_of_view.c\
		mini_map.c\
		mlx_put.c\
		ray_casting.c\
		textures_mapping.c\
		player_movmentes.c\
		rotation.c\
		parsing/Libft/ft_itoa.c\
		rander_map.c\
		virtical_ray.c\
		virtical_ray2.c\
		horizontal_ray.c\
		horizontal_ray2.c\
		get_color.c\
		parsing/parsing.c\
		parsing/Libft/ft_strcmp.c\
		parsing/Libft/ft_strchr.c\
		parsing/Libft/ft_strrchr.c\
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
NAME = cub3d_bonus

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS)  -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	
%.o: %.c
	$(CC) -Imlx -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all