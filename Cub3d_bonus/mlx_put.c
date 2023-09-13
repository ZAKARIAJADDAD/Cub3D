/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:31:47 by zael-wad          #+#    #+#             */
/*   Updated: 2023/09/13 11:22:28 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	my_mlx_get_add(t_var *data, int x, int y)
{
	char	*dst;

	dst = data->textuer.add + (y * data->textuer.line_length + \
	x * (data->textuer.bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	my_mlx_pixel_put(t_var *data, int x, int y, int color)
{
	char	*dst;

	if (x > 0 && y > 0 && x < data->x_screen && y < data->y_screen)
	{
		dst = data->addr + (y * data->line_length + x \
		* (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
