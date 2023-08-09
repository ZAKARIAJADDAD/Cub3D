/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:18:59 by zael-wad          #+#    #+#             */
/*   Updated: 2023/08/09 13:26:40 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line/get_next_line.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ROTATE_ANGLE 0.0872665
# define PLAYER_ANGLE 4.71239

# define BLACK 0x00000000
# define WHITE 0x00FFFFFF
# define RED 0x00FF0000
# define CYAN 0x0000FFFF
# define GREEN 0x0000FF00
# define DARK_TURQUOISE 0x0000CED1
# define BLUE 0x000000FF
# define PI 3.14159265359
# define PLAYER_SPEED 3
# define LINE_LENTH 30
# define GRIDE_SIZE 50

typedef struct t_player
{
	double		ray_angle;
	double		line_lenth;
	double		save_y_inc;
	double		save_x_inc;
	double		player_speed;
	double		line_x_start;
	double		line_y_start;
	double		player_x;
	double		player_y;
	int			map2d_x;
	int			map2d_y;
	double		x_horizontal_line_end;
	double		y_horizontal_line_end;
	double		x_virtical_line_end;
	double		y_virtical_line_end;
	double		x_line_end;
	double		y_line_end;
	double		angle_in_radian;
}				t_player;

typedef struct t_var
{
	// int             x_width;
	// int             y_height;
	double		tmp_player_x;
	double		tmp_player_y;
	double		store_cos;
	double		store_sin;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_player	player_pos;
	char		**tmp_arry;
	char		**tmp_arry2;
	void		*mlx;
	char		**map2d;
	void		*mlx_win;
}				t_var;

char			**ft_split(char const *st, char c);
char			**cpy(char const *st, char **str, char c);
char			**sto(char const *st, char **str, char c);
int				wdcount(char const *s2, char c, int i);
int				x_width(char **p);
int				y_height(char **p);
char			*ft_strjoin_split(char *s1, char *s2);
char			*ft_join(int fd);
char			**ftt_split(t_var *data, int fd);
char			*join_utils(char *s1);
// mao2d

void			fill_wall(t_var *img, int y, int x);
void			fill_ground(t_var *img, int y, int x);
void			player_fill(t_var *img, int y, int x);

void			my_mlx_pixel_put(t_var *data, int x, int y, int color);
void			update_player_pos(t_var *img, int x, int y, int key);

void			first_fill_ground(t_var *img, int x, int y);

// movmentes
void			move_forward(t_var *data);
void			move_back(t_var *data);
void			move_right(t_var *data);
void			move_left(t_var *data);

// rotiation

void			rotate_left(t_var *data);
void			rotate_right(t_var *data);

// draw line
void			draw_line(t_var *data);
// void			draw_line2(t_var *data);
void			player_direction(t_var *data);
void			first_draw_line(t_var *data);
void			horizotal_ray(t_var *data);
void			virtical_ray(t_var *data);

// rander map2d
int				first_rander_map2d(t_var *img);
int				rander_map2d(t_var *img);
void			clac_player_distence(t_var *data);


//files of  view
void	player_view_filed(t_var *data);
#endif