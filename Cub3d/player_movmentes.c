/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movmentes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:44:04 by zael-wad          #+#    #+#             */
/*   Updated: 2023/09/13 14:32:59 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_2var	*data)
{
	data->store_cos = cos(data->player_pos.angle_in_radian) * PLAYER_SPEED;
	data->store_sin = sin(data->player_pos.angle_in_radian) * PLAYER_SPEED;
	data->tmp_player_x = data->player_pos.player_x + data->store_cos;
	data->tmp_player_y = data->player_pos.player_y + data->store_sin;
}

void	move_back(t_2var	*data)
{
	data->store_cos = cos(data->player_pos.angle_in_radian) * PLAYER_SPEED;
	data->store_sin = sin(data->player_pos.angle_in_radian) * PLAYER_SPEED;
	data->tmp_player_x = data->player_pos.player_x - data->store_cos;
	data->tmp_player_y = data->player_pos.player_y - data->store_sin;
}

void	move_right(t_2var	*data)
{
	data->store_cos = \
	cos(data->player_pos.angle_in_radian + PI / 2) * PLAYER_SPEED;
	data->store_sin = \
	sin(data->player_pos.angle_in_radian + PI / 2) * PLAYER_SPEED;
	data->tmp_player_x = data->player_pos.player_x + data->store_cos;
	data->tmp_player_y = data->player_pos.player_y + data->store_sin;
}

void	move_left(t_2var	*data)
{
	data->store_cos = \
	cos(data->player_pos.angle_in_radian + PI / 2) * PLAYER_SPEED;
	data->store_sin = \
	sin(data->player_pos.angle_in_radian + PI / 2) * PLAYER_SPEED;
	data->tmp_player_x = data->player_pos.player_x - data->store_cos;
	data->tmp_player_y = data->player_pos.player_y - data->store_sin;
}
