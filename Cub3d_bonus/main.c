/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:18:38 by zael-wad          #+#    #+#             */
/*   Updated: 2023/09/13 12:25:16 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <math.h>
#include <limits.h>

void	initialize_mlx(t_var *data)
{
	data->mlx_win = \
	mlx_new_window(data->mlx, data->x_screen, data->y_screen, "map");
	data->img = \
	mlx_new_image(data->mlx, data->x_screen, data->y_screen);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
	&data->line_length, &data->endian);
}

void	raycasting(char **av)
{
	t_var	*img;

	img = malloc(sizeof(t_var));
	map_parsing(av[1], &img);
	img->mlx = mlx_init();
	initialize_varibles(img);
	initialize_mlx(img);
	player_map_position(img);
	player_view_filed(img);
	load_texture(img);
	mlx_mouse_move(img->mlx, img->mlx_win, \
	img->x_screen / 2, img->y_screen / 2);
	mlx_mouse_hide(img->mlx, img->mlx_win);
	mlx_hook(img->mlx_win, 17, 0, mouse_press, img);
	mlx_hook(img->mlx_win, 2, (1L << 0), &move_player, img);
	mlx_loop_hook(img->mlx, move_mouse, img);
	mlx_loop(img->mlx);
	free(img);
	free(img->mlx);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		raycasting(av);
	else
		write(2, "Error: program requires two arguments!!\n", 40);
	return (0);
}
