/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:45:43 by saguesse          #+#    #+#             */
/*   Updated: 2022/10/04 16:43:27 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_pressed(int keycode, t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	if (keycode == XK_Escape)
		close_win(data);
	else if (keycode == UP)
		data->draw.y -= 20;
	else if (keycode == DOWN)
		data->draw.y += 20;
	else if (keycode == RIGHT)
		data->draw.x += 20;
	else if (keycode == LEFT)
		data->draw.x -= 20;
	else if (keycode == P)
		data->draw.view = 1;
	else if (keycode == I)
		data->draw.view = 0;
	else if (keycode == C)
		change_color(data);
	else if (keycode == W)
		data->draw.height += 0.1;
	else if (keycode == S)
		data->draw.height -= 0.1;
	return (0);
}

int	button_pressed(int keycode, int x, int y, t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	(void)x;
	(void)y;
	if (keycode == ZOOM_IN)
		data->draw.zoom += 0.1;
	else if (keycode == ZOOM_OUT)
	{
		if (data->draw.zoom > 0.1)
			data->draw.zoom -= 0.1;
	}
	return (0);
}
