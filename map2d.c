/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:24:26 by zael-wad          #+#    #+#             */
/*   Updated: 2023/08/17 21:41:33 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	player_fill(t_var *img, int y, int x)
{
	int i;
	int j;

	i = y - 50;
	while (i < y)
	{
		j = x - 50;
		while (j < x)
		{
			if (i == (y - 25) && j == (x - 25))
            {
                img->player_pos.player_x = j;
                img->player_pos.player_y = i;
				printf("%d\n",(int)img->player_pos.player_x );
				printf("%d\n",(int)img->player_pos.player_y );
            }
			j++;
		}
		i++;
	}
}
void mini_map_pos(t_var *img, int y, int x)
{

	int i;
	int j;

	i = y - 40;
	while (i < y)
	{
		j = x - 40;
		while (j < x)
		{
			if (i == (y - 20) && j == (x - 20))
            {
                img->player_2d.x_2d = j;
                img->player_2d.y_2d = i;
				// printf("%d\n",(int)img->player_pos.x2d );
				// printf("%d\n",(int)img->player_pos.y2d );
            }
			j++;
		}
		i++;
	}
}

void	update_player_pos(t_var *img, int y, int x, int key)
{
	int i;
	int j;

	i = y - 40;
	while (i < y)
	{
		j = x - 40;
		while (j < x)
		{
			if (j % 40 == 0 || i % 40 == 0)
				my_mlx_pixel_put(img, j , i , WHITE);
			else	
				my_mlx_pixel_put(img, j , i , DARK_TURQUOISE);
			j++;
		}
		i++;
	}
}

void	fill_wall(t_var *img, int y, int x)
{
	int i;
	int j;
	
	i = y - 40;
	while (i < y)
	{
		j = x - 40;
		while (j  < x)
		{
			if (j % 40 == 0 || i % 40 == 0)
				my_mlx_pixel_put(img, j , i , WHITE);
			else
				my_mlx_pixel_put(img, j , i, BLUE);
			j++;
		}
		i++;
	}
}


void	fill_ground(t_var *img, int y, int x)
{
	int i ;
	int j ;
	
	i = y - 40;

	while (i < y)
	{
		j = x - 40;
		while (j < x)
		{
			if (j % 40 == 0 || i % 40 == 0)
				my_mlx_pixel_put(img, j , i , WHITE);
			else
				my_mlx_pixel_put(img, j , i , DARK_TURQUOISE);
			j++;
		}
		i++;
	}
}

void	first_fill_ground(t_var *img, int y, int x)
{
	int i ;
	int j ;
	
	i = y - 40;
	while (i < y)
	{
		j = x - 40;
		while (j < x)
		{
			if (j % 40 == 0 || i % 40 == 0)
				my_mlx_pixel_put(img, j , i , WHITE);
			else
				my_mlx_pixel_put(img, j , i , DARK_TURQUOISE);
			j++;
		}
		i++;
	}
}