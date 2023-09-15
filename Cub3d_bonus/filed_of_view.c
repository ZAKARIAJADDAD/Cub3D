/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filed_of_view.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:33:11 by zael-wad          #+#    #+#             */
/*   Updated: 2023/09/15 19:44:20 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	player_view_filed(t_var *data)
{
	int		i;
	double	steps;

	i = 0;
	clac_projextion_distance(data);
	data->player_pos.ray_angle = data->player_pos.angle_in_radian;
	steps = convert_dgree(60) / data->x_screen;
	while (i < data->x_screen / 2)
	{
		data->player_pos.ray_angle -= steps;
		if (data->player_pos.ray_angle < 0)
			data->player_pos.ray_angle = 2 * PI;
		i++;
	}
	i = 0;
	while (i < data->x_screen)
	{
		if (data->player_pos.ray_angle > 2 * PI)
			data->player_pos.ray_angle = 0;
		data->player_pos.ray_angle += steps;
		draw_line(data, i);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

void	ray_calc(t_var *data, int x_pos)
{
	int	stps;

	virtical_ray(data);
	horizotal_ray(data);
	clac_player_distence(data);
	fix_distortion(data);
	find_y_inc(data, x_pos);
	draw_sky(data, x_pos, data->dda_data.start, \
	data->dda_data.projected_slice_height);
	if (data->textuer.textuer_y_hight > data->dda_data.projected_slice_height)
		stps = data->textuer.textuer_y_hight / \
		data->dda_data.projected_slice_height;
	else
		stps = data->dda_data.projected_slice_height / \
		data->textuer.textuer_y_hight;
}

void	draw_line(t_var *data, int x_pos)
{
	int	i;

	i = 0;
	ray_calc(data, x_pos);
	if (data->dda_data.steps > data->y_screen)
	{
		data->dda_data.steps = data->y_screen;
		data->dda_data.start = 0;
	}
	i = data->dda_data.start;
	while (i <= data->dda_data.steps + data->dda_data.start)
	{
		data->dda_data.y_tex = i - (data->y_screen - data->dda_data.projected_slice_height) / 2;
		if (data->player_pos.virtical_distance < \
			data->player_pos.horizontal_distance)
			virtical_mapping(data);
		else
			horizontal_mapping(data);
		my_mlx_pixel_put(data, x_pos, i, \
			data->dda_data.texture_color);
		i++;
	}
}
