/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtical_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:51:45 by zael-wad          #+#    #+#             */
/*   Updated: 2023/09/12 21:54:45 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	vir_ray_to_infinity(t_var	*data)
{
	data->player_pos.x_virtical_line_end = INT_MAX;
	data->player_pos.y_virtical_line_end = INT_MAX;
}

int	vir_find_first_point(t_var	*data)
{
	if (sin(data->player_pos.ray_angle) == 0 || \
		cos(data->player_pos.ray_angle) == 0)
		return (1);
	if (data->player_pos.ray_angle > convert_dgree(90) && \
			data->player_pos.ray_angle < convert_dgree(270))
		data->vray_data.alpha_x = (floor((int)data->player_pos.player_x \
		/ GRIDE_SIZE) * GRIDE_SIZE) - 0.001;
	else
		data->vray_data.alpha_x = (floor((int)data->player_pos.player_x \
			/ GRIDE_SIZE) * GRIDE_SIZE) + 50;
	data->vray_data.alpha_y = (data->vray_data.alpha_x - \
	data->player_pos.player_x) * tan(data->player_pos.ray_angle);
	if (data->player_pos.ray_angle > 0 && \
			data->player_pos.ray_angle < convert_dgree(180))
		data->vray_data.alpha_y = \
			data->player_pos.player_y + fabs(data->vray_data.alpha_y);
	else
		data->vray_data.alpha_y = \
			data->player_pos.player_y - fabs(data->vray_data.alpha_y);
	return (0);
}

int	vir_first_intersection(t_var *data)
{
	vir_ray_to_infinity(data);
	if (vir_find_first_point(data))
		return (1);
	if (data->player_pos.ray_angle > convert_dgree(90) && \
	data->player_pos.ray_angle < convert_dgree(270))
		data->vray_data.xs = -GRIDE_SIZE;
	else
		data->vray_data.xs = GRIDE_SIZE;
	data->vray_data.ys = data->vray_data.xs * tan(data->player_pos.ray_angle);
	if (data->vray_data.alpha_x < 0 || data->vray_data.alpha_y < 0 || \
	data->vray_data.alpha_x >= data->x_width || \
	data->vray_data.alpha_y >= data->y_height)
	{
		vir_ray_to_infinity(data);
		return (1);
	}
	return (0);
}

int	vir_check_if_wall(t_var *data)
{
	if (data->map2d[(int)data->vray_data.old_ys / GRIDE_SIZE] \
	[(int)data->vray_data.old_xs / GRIDE_SIZE] != '1')
	{
		data->vray_data.old_xs += data->vray_data.xs;
		data->vray_data.old_ys += data->vray_data.ys;
		return (0);
	}
	else if (data->map2d[(int)data->vray_data.old_ys / GRIDE_SIZE] \
	[(int)data->vray_data.old_xs / GRIDE_SIZE] != '0')
	{
		data->player_pos.x_virtical_line_end = data->vray_data.old_xs;
		data->player_pos.y_virtical_line_end = data->vray_data.old_ys;
		return (1);
	}
	return (0);
}

void	virtical_ray(t_var	*data)
{
	if (vir_first_intersection(data))
		return ;
	if (data->map2d[(int)data->vray_data.alpha_y / GRIDE_SIZE] \
	[(int)data->vray_data.alpha_x / GRIDE_SIZE] == '1')
	{
		data->player_pos.x_virtical_line_end = data->vray_data.alpha_x;
		data->player_pos.y_virtical_line_end = data->vray_data.alpha_y;
		return ;
	}
	else
	{
		data->vray_data.old_xs = data->vray_data.xs + data->vray_data.alpha_x;
		data->vray_data.old_ys = data->vray_data.ys + data->vray_data.alpha_y;
		while (1)
		{
			if (vir_while_conditions(data) == 1)
				return ;
		}
	}
}
