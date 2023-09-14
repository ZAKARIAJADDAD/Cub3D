/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:09:14 by zjaddad           #+#    #+#             */
/*   Updated: 2023/09/14 23:34:32 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color_texture(t_2tex *tex, int i, int j, int s_wall)
{
	char	*color;
	int		x;
	int		y;

	x = i % 50;
	y = (j * 50 / s_wall) % 50;
	color = tex->buffer + (y * tex->line_length) + \
	(x * (tex->bits_per_pixel / 8));
	return (*(int *)color);
}

void	get_image(t_2var *data, t_2tex *tex, char *path)
{
	tex->texture_ptr = mlx_xpm_file_to_image(data->mlx, path, \ &tex->textuer_x_width, &tex->textuer_y_hight);
	if (!tex->texture_ptr)
		exit(ft_error("Error: in img\n", 2));
	tex->buffer = mlx_get_data_addr(tex->texture_ptr, \
	&tex->bits_per_pixel, &tex->line_length, &tex->endian);
}

int	get_colors(t_2tex *tex, int x, int y)
{
	char	*dst;

	if (x >= 0 && x < tex->textuer_x_width \
	&& y >= 0 && y < tex->textuer_y_hight)
	{
		dst = tex->buffer + \
		(y * tex->line_length + x * (tex->bits_per_pixel / 8));
		return (*(unsigned int *)dst);
	}
	return (0);
}

int	get_pos(double pos, int w)
{
	int	x;

	x = ((pos / 50) - (int)(pos / 50)) * w;
	return (x);
}
