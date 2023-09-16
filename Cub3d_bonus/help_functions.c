/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:16:47 by zael-wad          #+#    #+#             */
/*   Updated: 2023/09/16 00:17:40 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_sky(t_var *data, int x, int start, int end)
{
	int	i;
	int	j;

	j = 0;
	while (j <= start)
		my_mlx_pixel_put(data, x, j++, data->ceiling_color);
	i = start + end;
	while (i <= data->y_screen)
		my_mlx_pixel_put(data, x, i++, data->floor_color);
}

double	convert_dgree(int degree)
{
	return (degree * (PI / 180));
}

void	player_direction(t_var *data, char c)
{
	if (c == 'E')
		data->player_pos.angle_in_radian = convert_dgree(0);
	else if (c == 'S')
		data->player_pos.angle_in_radian = convert_dgree(90);
	else if (c == 'W')
		data->player_pos.angle_in_radian = convert_dgree(180);
	else if (c == 'N')
		data->player_pos.angle_in_radian = convert_dgree(270);
}

void	find_y_height(t_var *data)
{
	int	i;

	i = 0;
	data->map2d = data->env2d;
	while (data->map2d[i])
		i++;
	data->y_height = i * 50;
}

void	initialize_varibles(t_var *data)
{
	find_y_height(data);
	data->player_pos.player_x = 0;
	data->player_pos.horizontal_distance = 0;
	data->player_pos.virtical_distance = 0;
	data->player_pos.player_y = 0;
	data->player_pos.player_speed = 3;
	data->player_pos.x_virtical_line_end = 0;
	data->player_pos.y_virtical_line_end = 0;
	data->player_pos.x_horizontal_line_end = 0;
	data->player_pos.y_horizontal_line_end = 0;
	data->player_pos.ray_angle = 0;
	data->player_pos.line_lenth = 0;
	data->store_cos = 0;
	data->store_sin = 0;
	data->mouse_x = data->x_screen / 2;
	data->mouse_y = data->y_screen / 2;
	data->x_screen = 1000;
	data->y_screen = 500;
	data->x_width = 33 * 50;
	data->old_mouse_x = 0;
	data->old_mouse_y = 0;
}
