/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtical_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:51:45 by zael-wad          #+#    #+#             */
/*   Updated: 2023/09/11 16:35:38 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"


// void	find_xs(t_var *data)
// {
	
	
// }

int	first_intersection(t_var *data)
{
	// find_xs(data);
	if(sin(data->player_pos.ray_angle) == 0 || cos(data->player_pos.ray_angle) == 0)
		return 1;
	if (data->player_pos.ray_angle > convert_dgree(90) && data->player_pos.ray_angle < convert_dgree(270))
		data->ray_data.alpha_x = (floor((int)data->player_pos.player_x / GRIDE_SIZE) * GRIDE_SIZE) - 0.001;
	else
		data->ray_data.alpha_x = (floor((int)data->player_pos.player_x / GRIDE_SIZE) * GRIDE_SIZE) + 50;
	
	data->ray_data.alpha_y =  (data->ray_data.alpha_x - data->player_pos.player_x) * tan(data->player_pos.ray_angle);

	if (data->player_pos.ray_angle > 0 && data->player_pos.ray_angle < convert_dgree(180))
		data->ray_data.alpha_y = data->player_pos.player_y + fabs(data->ray_data.alpha_y);
	else 
		data->ray_data.alpha_y = data->player_pos.player_y - fabs(data->ray_data.alpha_y);
	
	if (data->player_pos.ray_angle > convert_dgree(90) && data->player_pos.ray_angle <  convert_dgree(270))
		data->ray_data.xs = -GRIDE_SIZE;
	else
		data->ray_data.xs = GRIDE_SIZE;
		
	data->ray_data.ys = data->ray_data.xs * tan(data->player_pos.ray_angle);
	if (data->ray_data.alpha_x < 0 || data->ray_data.alpha_y < 0 || data->ray_data.alpha_x >= data->x_width || data->ray_data.alpha_y >= data->y_height)
	{
		data->player_pos.x_virtical_line_end = INT_MAX;
		data->player_pos.y_virtical_line_end = INT_MAX;
		return 1;
	}
	return 0;
}

void	virtical_ray(t_var *data)
{
	
	data->player_pos.x_virtical_line_end = INT_MAX;
	data->player_pos.y_virtical_line_end = INT_MAX;
	if (first_intersection(data))
		return ;
	if (data->map2d[(int)data->ray_data.alpha_y / GRIDE_SIZE][(int)data->ray_data.alpha_x / GRIDE_SIZE] == '1')
	{
		data->player_pos.x_virtical_line_end = data->ray_data.alpha_x;
		data->player_pos.y_virtical_line_end = data->ray_data.alpha_y;
		return;
	}
	else
	{
		data->ray_data.old_xs = data->ray_data.xs + data->ray_data.alpha_x;
		data->ray_data.old_ys = data->ray_data.ys + data->ray_data.alpha_y;
		while (1)
		{
			if (data->ray_data.old_xs < 0)
				data->ray_data.old_xs = data->ray_data.xs;
			if (data->ray_data.old_ys < 0)
				data->ray_data.old_ys = data->ray_data.ys;
			if (data->ray_data.old_xs > 0 && data->ray_data.old_ys > 0 && data->ray_data.old_xs < data->x_width && data->ray_data.old_ys < data->y_height)
			{
				if (data->map2d[(int)data->ray_data.old_ys / GRIDE_SIZE][(int)data->ray_data.old_xs  / GRIDE_SIZE] == '0')
				{
					data->ray_data.old_xs += data->ray_data.xs;
					data->ray_data.old_ys += data->ray_data.ys;
				}
				else if (data->map2d[(int)data->ray_data.old_ys  / GRIDE_SIZE][(int)data->ray_data.old_xs / GRIDE_SIZE] == '1')
				{

					data->player_pos.x_virtical_line_end = data->ray_data.old_xs;
					data->player_pos.y_virtical_line_end = data->ray_data.old_ys;
					break;
				}
			}
			else
			{
				data->player_pos.x_virtical_line_end = INT_MAX;
				data->player_pos.y_virtical_line_end = INT_MAX;
				return;
			}
		}
	}
}
