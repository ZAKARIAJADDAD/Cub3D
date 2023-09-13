/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_mapping.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:45:32 by zael-wad          #+#    #+#             */
/*   Updated: 2023/09/13 14:32:20 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	textuers(double x, double y, t_2var *data)
{
	data->textuer.x_wall_pos = (int)x % GRIDE_SIZE;
	data->textuer.y_wall_pos = (int)y % GRIDE_SIZE;
	data->textuer.texture_x = (data->textuer.x_wall_pos * 100) / GRIDE_SIZE;
	data->textuer.texture_y = (data->textuer.y_wall_pos * 100) / GRIDE_SIZE;
}

void	load_texture(t_2var *data)
{
	t_2map	*tmp;

	tmp = data->map;
	get_image(data, &data->textuer, tmp->value);
	get_image(data, &data->textuer1, tmp->next->value);
	get_image(data, &data->textuer2, tmp->next->next->value);
	get_image(data, &data->textuer3, tmp->next->next->next->value);
}
