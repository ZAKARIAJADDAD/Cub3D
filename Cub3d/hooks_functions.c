/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:45:47 by zael-wad          #+#    #+#             */
/*   Updated: 2023/09/13 17:27:57 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_fun(t_2var *data)
{
	exit (3);
}

int	mouse_press(t_2var *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
	return (0);
}

void	key_events(t_2var *data, int i)
{
	if (i == 65307)
		destroy_fun(data);
	if (i == 119)
		move_forward(data);
	if (i == 115)
		move_back(data);
	if (i == 97)
		move_left(data);
	if (i == 100)
		move_right(data);
	if (i == 65363)
		rotate_right(data);
	if (i == 65361)
		rotate_left(data);
}

int	move_player(int i, t_2var *data)
{
	data->tmp_player_x = data->player_pos.player_x;
	data->tmp_player_y = data->player_pos.player_y;
	key_events(data, i);
	if ((data->map2d[((int)data->tmp_player_y) / GRIDE_SIZE] \
	[((int)data->tmp_player_x) / GRIDE_SIZE] != '1') \
	&& (data->map2d[(int)data->tmp_player_y / 50] \
	[(int)data->player_pos.player_x / 50] != '1' \
	&& data->map2d[(int)data->player_pos.player_y / 50] \
	[(int)data->tmp_player_x / 50] != '1'))
	{
		data->player_pos.player_y = data->tmp_player_y;
		data->player_pos.player_x = data->tmp_player_x;
	}
	return (0);
}
