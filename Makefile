# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 14:19:07 by zael-wad          #+#    #+#              #
#    Updated: 2023/09/13 13:00:04 by zael-wad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3d

NAME_BONUS = cub3d_bonus 

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror

SRCS	= 	Cub3d/main.c\
			Cub3d/filed_of_view.c\
			Cub3d/mlx_put.c\
			Cub3d/ray_casting.c\
			Cub3d/textures_mapping.c\
			Cub3d/player_movmentes.c\
			Cub3d/rotation.c\
			Cub3d/help_functions.c\
			Cub3d/parsing/Libft/ft_itoa.c\
			Cub3d/rander_map.c\
			Cub3d/virtical_ray.c\
			Cub3d/virtical_ray2.c\
			Cub3d/horizontal_ray.c\
			Cub3d/horizontal_ray2.c\
			Cub3d/get_color.c\
			Cub3d/hooks_functions.c\
			Cub3d/parsing/parsing.c\
			Cub3d/parsing/Libft/ft_strcmp.c\
			Cub3d/parsing/Libft/ft_strchr.c\
			Cub3d/parsing/Libft/ft_strrchr.c\
			Cub3d/parsing/get_next_line/get_next_line.c\
			Cub3d/parsing/Libft/ft_strjoin.c\
			Cub3d/parsing/Libft/ft_substr.c\
			Cub3d/parsing/Libft/ft_split.c \
			Cub3d/parsing/Libft/ft_putstr_fd.c\
			Cub3d/parsing/Libft/ft_strtrim.c\
			Cub3d/parsing/Libft/ft_strncmp.c\
			Cub3d/parsing/Libft/ft_isdigit.c\
			Cub3d/parsing/Libft/ft_atoi.c\
			Cub3d/parsing/get_next_line/get_next_line_utils.c\
			Cub3d/parsing/Parsing/map_validation.c\
			Cub3d/parsing/Parsing/ft_lstnew_s.c\
			Cub3d/parsing/Parsing/ft_lstadd_back_s.c\
			Cub3d/parsing/Parsing/map_processing.c\
			Cub3d/parsing/Parsing/ft_errors.c\
			Cub3d/parsing/Parsing/player.c\
			Cub3d/parsing/Parsing/check_colors.c\
			Cub3d/parsing/Parsing/check_spaces.c\

SRCS_BONUS	= 	Cub3d_bonus/main.c\
				Cub3d_bonus/mouse_move.c\
				Cub3d_bonus/filed_of_view.c\
				Cub3d_bonus/mini_map.c\
				Cub3d_bonus/mlx_put.c\
				Cub3d_bonus/ray_casting.c\
				Cub3d_bonus/textures_mapping.c\
				Cub3d_bonus/player_movmentes.c\
				Cub3d_bonus/rotation.c\
				Cub3d_bonus/help_functions.c\
				Cub3d_bonus/parsing/Libft/ft_itoa.c\
				Cub3d_bonus/rander_map.c\
				Cub3d_bonus/virtical_ray.c\
				Cub3d_bonus/virtical_ray2.c\
				Cub3d_bonus/horizontal_ray.c\
				Cub3d_bonus/horizontal_ray2.c\
				Cub3d_bonus/get_color.c\
				Cub3d_bonus/hooks_functions.c\
				Cub3d_bonus/parsing/parsing.c\
				Cub3d_bonus/parsing/Libft/ft_strcmp.c\
				Cub3d_bonus/parsing/Libft/ft_strchr.c\
				Cub3d_bonus/parsing/Libft/ft_strrchr.c\
				Cub3d_bonus/parsing/get_next_line/get_next_line.c\
				Cub3d_bonus/parsing/Libft/ft_strjoin.c\
				Cub3d_bonus/parsing/Libft/ft_substr.c\
				Cub3d_bonus/parsing/Libft/ft_split.c \
				Cub3d_bonus/parsing/Libft/ft_putstr_fd.c\
				Cub3d_bonus/parsing/Libft/ft_strtrim.c\
				Cub3d_bonus/parsing/Libft/ft_strncmp.c\
				Cub3d_bonus/parsing/Libft/ft_isdigit.c\
				Cub3d_bonus/parsing/Libft/ft_atoi.c\
				Cub3d_bonus/parsing/get_next_line/get_next_line_utils.c\
				Cub3d_bonus/parsing/Parsing/map_validation.c\
				Cub3d_bonus/parsing/Parsing/ft_lstnew_s.c\
				Cub3d_bonus/parsing/Parsing/ft_lstadd_back_s.c\
				Cub3d_bonus/parsing/Parsing/map_processing.c\
				Cub3d_bonus/parsing/Parsing/ft_errors.c\
				Cub3d_bonus/parsing/Parsing/player.c\
				Cub3d_bonus/parsing/Parsing/check_colors.c\
				Cub3d_bonus/parsing/Parsing/check_spaces.c\

OBJ = $(SRCS:.c=.o)
OBJB = $(SRCS_BONUS:.c=.o)


all : $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(NAME_BONUS) : $(OBJB)
	$(CC) $(OBJB) $(CFLAGS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME_BONUS)

%.o: %.c
	$(CC) -Imlx -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f $(OBJB)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all