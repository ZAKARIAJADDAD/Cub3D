/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:30:06 by zael-wad          #+#    #+#             */
/*   Updated: 2023/09/17 17:46:11 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	fill_player(t_var *data)
{
	my_mlx_pixel_put(data, data->mini_map.x - 1, data->mini_map.y - 1, BLACK);
	my_mlx_pixel_put(data, data->mini_map.x, data->mini_map.y - 1, BLACK);
	my_mlx_pixel_put(data, data->mini_map.x - 1, data->mini_map.y, BLACK);
	my_mlx_pixel_put(data, data->mini_map.x, data->mini_map.y, BLACK);
}

void	pixel_put(t_var *data)
{
	if (data->mini_map.x == 50 && data->mini_map.y == 50)
		fill_player(data);
	if (data->mini_map.y == 1 || data->mini_map.y == 2 \
	|| data->mini_map.y == 100 || data->mini_map.y == 99 \
	|| data->mini_map.x == 1 || data->mini_map.x == 2 || \
	data->mini_map.x == 200 || data->mini_map.x == 199)
		my_mlx_pixel_put(data, data->mini_map.x, data->mini_map.y, WHITE);
	else if (data->map2d[data->mini_map.y_pos / 50] \
	[data->mini_map.x_pos / 50] != '1')
		my_mlx_pixel_put(data, data->mini_map.x, data->mini_map.y, GROUND);
	else if (data->map2d[data->mini_map.y_pos / 50] \
	[data->mini_map.x_pos / 50] == '1')
		my_mlx_pixel_put(data, data->mini_map.x, \
		data->mini_map.y, DARK_TURQUOISE);
}

void	mini_map(t_var *data)
{
	data->mini_map.y = 0;
	data->mini_map.x_pos = data->player_pos.player_x - 50;
	data->mini_map.y_pos = data->player_pos.player_y - 50;
	while (data->mini_map.y <= 100)
	{
		data->mini_map.x = 0;
		data->mini_map.x_pos = data->player_pos.player_x - 50;
		while (data->mini_map.x <= 200)
		{
			pixel_put(data);
			data->mini_map.x_pos++;
			data->mini_map.x++;
		}
		data->mini_map.y_pos++;
		data->mini_map.y++;
	}
}
