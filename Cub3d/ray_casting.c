/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:01:02 by zael-wad          #+#    #+#             */
/*   Updated: 2023/09/13 14:32:02 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clac_projextion_distance(t_2var *data)
{
	data->distance_to_projection_plane = \
	tan(convert_dgree(30)) * ((int)data->x_screen/ 2);
}

void	find_y_inc(t_2var *data, int x_pos)
{
	double	wall_center;
	double	start;
	double	dx;
	double	dy;

	wall_center = (data->y_screen / 2);
	data->dda_data.start = wall_center - \
	(data->dda_data.projected_slice_height / 2);
	dx = x_pos;
	dy = data->dda_data.projected_slice_height;
	data->dda_data.steps = fabs(dy);
	data->dda_data.y_inc = dy / data->dda_data.steps;
}

void	fix_distortion(t_2var	*data)
{
	if (data->player_pos.ray_angle < data->player_pos.angle_in_radian)
		data->player_pos.distance = data->player_pos.distance * \
	cos((data->player_pos.ray_angle - data->player_pos.angle_in_radian));
	else
		data->player_pos.distance = data->player_pos.distance * \
	cos((data->player_pos.angle_in_radian - data->player_pos.ray_angle));
	data->dda_data.projected_slice_height = \
	GRIDE_SIZE / data->player_pos.distance * data->distance_to_projection_plane;
	if (data->dda_data.projected_slice_height < 0)
		data->dda_data.projected_slice_height = 0;
}

void	virtical_mapping(t_2var	*data)
{
	int	k;

	if (cos(data->player_pos.ray_angle) > 0)
	{
		data->dda_data.y_tex = \
		data->textuer2.textuer_y_hight / data->dda_data.projected_slice_height;
		k = get_pos(data->player_pos.y_virtical_line_end, \
		data->textuer2.textuer_x_width);
		data->dda_data.texture_color = \
		get_colors(&data->textuer2, k, data->dda_data.y_increament);
	}
	else
	{
		data->dda_data.y_tex = \
		data->textuer3.textuer_y_hight / data->dda_data.projected_slice_height;
		k = get_pos(data->player_pos.y_virtical_line_end, \
		data->textuer3.textuer_x_width);
		data->dda_data.texture_color = \
		get_colors(&data->textuer3, k, data->dda_data.y_increament);
	}
}

void	horizontal_mapping(t_2var *data)
{
	int	k;

	if (sin(data->player_pos.ray_angle) > 0)
	{
		data->dda_data.y_tex = \
		data->textuer.textuer_y_hight / data->dda_data.projected_slice_height;
		k = get_pos(data->player_pos.x_horizontal_line_end, \
		data->textuer.textuer_x_width);
		data->dda_data.texture_color = \
		get_colors(&data->textuer, k, data->dda_data.y_increament);
	}
	else
	{
		data->dda_data.y_tex = \
		data->textuer1.textuer_y_hight / data->dda_data.projected_slice_height;
		k = get_pos(data->player_pos.x_horizontal_line_end, \
		data->textuer1.textuer_x_width);
		data->dda_data.texture_color = \
		get_colors(&data->textuer1, k, data->dda_data.y_increament);
	}
}
