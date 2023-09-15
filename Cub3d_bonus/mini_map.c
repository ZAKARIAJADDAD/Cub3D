/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:30:06 by zael-wad          #+#    #+#             */
/*   Updated: 2023/09/15 15:19:45 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	fill_player(t_var *data , int x , int y)
{
	my_mlx_pixel_put(data, x - 1, y - 1, BLACK);
	my_mlx_pixel_put(data, x, y - 1, BLACK);
	my_mlx_pixel_put(data, x - 1, y, BLACK);
	my_mlx_pixel_put(data, x, y, BLACK);
}

void	pixel_put(t_var *data, int x, int y)
{
	
}
void	mini_map(t_var *data)
{
	int	y;
	int	x;
	int	x_pos;
	int	y_pos;

	y = 0;
	x_pos = data->player_pos.player_x - 50;
	y_pos = data->player_pos.player_y - 50;
	while (y <= 100)
	{
		x = 0;
		x_pos = data->player_pos.player_x - 50;
		while (x <= 200)
		{
			if (x == 50 && y == 50)
				fill_player(data, x, y);
			if (y == 1 || y == 2 || y == 100 || y == 99 \
			|| x == 1 || x == 2 || x == 200 || x == 199)
				my_mlx_pixel_put(data, x, y, WHITE);
			else if (data->map2d[y_pos / 50][x_pos / 50] == '1')
				my_mlx_pixel_put(data, x, y, GROUND);
			else if (data->map2d[y_pos / 50 ][x_pos / 50] != '1')
				my_mlx_pixel_put(data, x, y, DARK_TURQUOISE);
			// pixel_put(data, &x, &y);
			x_pos++;
			x++;
		}
		y_pos++;
		y++;
	}
}

