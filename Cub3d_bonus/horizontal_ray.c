/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:53:23 by zael-wad          #+#    #+#             */
/*   Updated: 2023/09/17 18:27:29 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	hor_ray_to_infinity(t_var	*data)
{
	data->player_pos.x_horizontal_line_end = INT_MAX - 1;
	data->player_pos.y_horizontal_line_end = INT_MAX - 1;
}

int	hor_find_first_point(t_var	*data)
{
	if (sin(data->player_pos.ray_angle) == 0 \
	|| cos(data->player_pos.ray_angle) == 0)
		return (1);
	if (data->player_pos.ray_angle > 0 && \
	data->player_pos.ray_angle < convert_dgree(180))
		data->hray_data.alpha_y = (floor((int)data->player_pos.player_y \
		/ GRIDE_SIZE) * GRIDE_SIZE) + GRIDE_SIZE;
	else
		data->hray_data.alpha_y = (floor((int)data->player_pos.player_y \
		/ GRIDE_SIZE) * GRIDE_SIZE) - 0.00005;
	data->hray_data.alpha_x = (data->player_pos.player_y \
	- data->hray_data.alpha_y) / tan(data->player_pos.ray_angle);
	if (data->player_pos.ray_angle > convert_dgree(90) \
	&& data->player_pos.ray_angle < convert_dgree(270))
		data->hray_data.alpha_x = \
		data->player_pos.player_x - fabs(data->hray_data.alpha_x);
	else
		data->hray_data.alpha_x = \
		data->player_pos.player_x + fabs(data->hray_data.alpha_x);
	return (0);
}

int	hor_first_intersection(t_var *data)
{
	hor_ray_to_infinity(data);
	if (hor_find_first_point(data))
		return (1);
	if (data->player_pos.ray_angle > 0 && \
	data->player_pos.ray_angle < convert_dgree(180))
		data->hray_data.ys = GRIDE_SIZE;
	else
		data->hray_data.ys = -GRIDE_SIZE;
	data->hray_data.xs = \
	data->hray_data.ys / tan(data->player_pos.ray_angle);
	if (data->hray_data.alpha_x < 0 || data->hray_data.alpha_y < 0 \
	|| data->hray_data.alpha_x >= data->x_width \
	|| data->hray_data.alpha_y >= data->y_height)
	{
		hor_ray_to_infinity(data);
		return (1);
	}
	return (0);
}

int	hor_check_if_wall(t_var *data)
{
	if (data->map2d[(int)data->hray_data.old_ys / GRIDE_SIZE] \
	[(int)data->hray_data.old_xs / GRIDE_SIZE] != '1' && \
	data->map2d[(int)data->hray_data.old_ys / GRIDE_SIZE] \
	[(int)data->hray_data.old_xs / GRIDE_SIZE] != ' ')
	{
		data->hray_data.old_xs += data->hray_data.xs;
		data->hray_data.old_ys += data->hray_data.ys;
		return (0);
	}
	else if (data->map2d[(int)data->hray_data.old_ys / GRIDE_SIZE] \
	[(int)data->hray_data.old_xs / GRIDE_SIZE] != '0')
	{
		data->player_pos.x_horizontal_line_end = data->hray_data.old_xs;
		data->player_pos.y_horizontal_line_end = data->hray_data.old_ys;
		return (1);
	}
	return (0);
}

void	horizotal_ray(t_var *data)
{
	if (hor_first_intersection(data))
		return ;
	if (data->map2d[(int)data->hray_data.alpha_y / GRIDE_SIZE] \
	[(int)data->hray_data.alpha_x / GRIDE_SIZE] == '1')
	{
		data->player_pos.x_horizontal_line_end = data->hray_data.alpha_x;
		data->player_pos.y_horizontal_line_end = data->hray_data.alpha_y;
	}
	else
	{
		data->hray_data.old_xs = data->hray_data.xs + data->hray_data.alpha_x;
		data->hray_data.old_ys = data->hray_data.alpha_y + data->hray_data.ys;
		while (1)
		{
			if (hor_while_conditions(data) == 1)
				return ;
		}
	}
}
