/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:18:59 by zael-wad          #+#    #+#             */
/*   Updated: 2023/09/04 11:22:14 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "parsing/get_next_line/get_next_line.h"
#include "mlx.h"
# include "parsing/Libft/libft.h"
# include <fcntl.h>
#include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ROTATE_ANGLE 0.0872665
# define PLAYER_ANGLE 4.71239

#define X_WIDTH 1200
#define Y_HEIGHT 400
# define BROWN	0x00E0E0E0
# define BLACK 	0x00000000
# define SKY	0x000080FF
# define GROUND 0x00A0A0A0
# define WHITE	0x00FFFFFF
# define RED	0x00FF0000
# define CYAN	0x0000FFFF
# define GREEN	0x0000FF00
# define BLUE	0x000000FF
# define DARK_TURQUOISE 0x0000CED1
# define PI 3.14159265358979323846
# define PLAYER_SPEED 3
# define LINE_LENTH 30
# define GRIDE_SIZE 50

typedef struct t_player
{


	double 		distance;
	double		pd;
	double		pe;
	double		old_x;
	double		old_y;
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

typedef struct t_map
{
	char			*key;
	char			*value;
	struct t_map	*next;
}	t_map;

typedef	struct  t_tex
{

	char		*add;
	void	*north_wall;
	void	*east_wall;
	void	*west_wall;
	void	*south_wall;

	int textuer_x_width;
	int textuer_y_hight;
	double x_wall_pos;
	double y_wall_pos;
	double texture_x;
	double texture_y;

	int			bits_per_pixel;
	int			line_length;
	int			endian;

}			 t_tex ;

typedef struct t_img
{
	int	width;
	int hight;
	void *ptr1;
   void *ptr2;
   void *ptr3;
   void *ptr4;
   void *ptr5;
   void *ptr6;
   void *ptr7;
   void *ptr8;
   void *ptr9;
   void *ptr10;
   void *ptr11;
   void *ptr12;
   void *ptr13;
   void *ptr14;
} t_img;

typedef struct t_var
{
	
	int			fd;
	int			i;
	int			j;
	int			count;
	char		**env2d;
	t_map		*map;
	t_tex		textuer;
	t_img		xpm_img;
	int 		test;

	int 		mouse_x;
	int 		mouse_y;
	double 		player_of_wall;
	double 		x_screen;
	double 		y_screen;
	int         x_width;
	int         y_height;
	double		distance_to_projection_plane;
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


// player
void	player_map_position(t_var *data);

////



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

void	draw_sky(t_var *data,int x, int start, int end);


// draw line
void			draw_line(t_var *data, int x_pos);
// void			draw_line2(t_var *data);
void			player_direction(t_var *data);
void			first_draw_line(t_var *data);
void			horizotal_ray(t_var *data);
void			virtical_ray(t_var *data);

// rander map2d
int				first_rander_map2d(t_var *img);
int				rander_map(t_var *img);
void			clac_player_distence(t_var *data);


//files of  view
void	player_view_filed(t_var *data);

double	convert_dgree(int degree);
void mini_map_pos(t_var *img, int y, int x);

//filed of view ray cast
void	horizotal_ray(t_var *data);
void	virtical_ray(t_var *data);


//bonus

// mouse movementes
int	move_mouse(t_var *data);

// animetion
void    add_xpm(t_var *data);

// /minimap
void	mini_map(t_var *img);


void	textuers(double x, double y, t_var *data);



// 2dmap
void    virtical_2d(t_var *data);
void    horizontal_2d(t_var *data);
void    clac_2dplayer_distence(t_var *data);

void	initlize_varibles(t_var *data);



int	parsing(int ac, char **av, t_var *data);
void	map_parsing(char *s, t_var **data);

/*********************************************************************/
/*                                 Parsing                           */
/*********************************************************************/

int				ft_error(char *s, int fd);
int				is_player(char c);
void    		player_position(t_var **data);
void			check_map(t_var **data);
void			check_colors(t_map *map);
void			check_spaces(char *s);
void    		check_file_path(t_map *map);
void			map_process(t_var **data, char *line);
void			ft_lstadd_back_s(t_map **head, t_map *new);
t_map			*ft_lstnew_s(char *key, char *value);
t_map			*ft_lstnew_s(char *key, char *value);
// void			map_parsing(char *s, t_var *data);

/*********************************************************************/
/*                                 Parsing                           */
/*********************************************************************/


#endif