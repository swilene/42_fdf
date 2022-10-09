/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 09:53:56 by saguesse          #+#    #+#             */
/*   Updated: 2022/10/04 16:54:47 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>

# include "mlx_linux/mlx.h"
# include "libft/libft.h"
# include "libft/ft_printf/libftprintf.h"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define WHITE 0xFFFFFF
# define RED 0xFF3333
# define ORANGE 0xFF9933
# define YELLOW 0xFFFF33
# define GREEN 0x00CC00
# define BLUE 0x0000FF
# define PURPLE 0x7F00FF
# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361
# define I 105
# define P 112
# define C 99
# define W 119
# define S 115
# define ZOOM_IN 4
# define ZOOM_OUT 5

typedef struct s_draw
{
	int		x;
	int		y;
	int		i;
	int		color;
	int		view;
	int		y_map;
	double	height;
	double	zoom;
}	t_draw;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_coord
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
}	t_coord;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_list	**map;
	t_coord	coord;
	t_draw	draw;
}	t_data;

int		count_lines(char *file);
int		init_window(t_data data);
int		render(t_data *data);
void	lines(t_data *data);
void	columns(t_data *data);
int		close_win(t_data *data);
void	ft_dellist(t_list **lst);
int		key_pressed(int keycode, t_data *data);
void	change_color(t_data *data);
int		button_pressed(int keycode, int x, int y, t_data *data);
void	img_pix_put(t_img *img, int x, int y, int color);

#endif
