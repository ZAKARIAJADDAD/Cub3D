/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:23:32 by zael-wad          #+#    #+#             */
/*   Updated: 2023/09/14 23:18:08 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	left_side(t_var *data)
{
	if (data->mouse_x < 0)
		mlx_mouse_move(data->mlx, data->mlx_win, data->x_screen / 2, \
			data->y_screen / 2);
	else if (data->mouse_x > data->x_screen || data->mouse_y > data->y_screen)
		mlx_mouse_move(data->mlx, data->mlx_win, data->x_screen / 2, \
			data->y_screen / 2);
	mlx_mouse_hide(data->mlx, data->mlx_win);
	data->player_pos.angle_in_radian -= convert_dgree(2);
	if (data->player_pos.angle_in_radian < 0)
		data->player_pos.angle_in_radian = 2 * PI;
}

void	right_side(t_var	*data)
{
	if (data->mouse_x < 0)
		mlx_mouse_move(data->mlx, data->mlx_win, data->x_screen / 2, \
			data->y_screen / 2);
	else if (data->mouse_x > data->x_screen || data->mouse_y > data->y_screen)
		mlx_mouse_move(data->mlx, data->mlx_win, data->x_screen / 2, \
			data->y_screen / 2);
	mlx_mouse_hide(data->mlx, data->mlx_win);
	data->player_pos.angle_in_radian += convert_dgree(2);
	if (data->player_pos.angle_in_radian > 2 * PI)
		data->player_pos.angle_in_radian = 0;
}

int	move_mouse(t_var	*data)
{
	int	old_mouse_x;
	int	old_mouse_y;

	old_mouse_x = data->mouse_x;
	old_mouse_y = data->mouse_y;
	mlx_mouse_get_pos(data->mlx, data->mlx_win, &data->mouse_x, &data->mouse_y);
	if (data->mouse_x < old_mouse_x)
		left_side(data);
	else if (data->mouse_x > old_mouse_x)
		right_side(data);
	mlx_clear_window(data->mlx, data->mlx_win);
	rander_map2d(data);
	// mini_map(data);
	return (1);
}
