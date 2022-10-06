/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:43:58 by saguesse          #+#    #+#             */
/*   Updated: 2022/10/05 17:56:15 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_win(t_data *data)
{
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->img.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	ft_dellist(data->map);
	exit(EXIT_SUCCESS);
	return (0);
}

void	init_params(t_data *data)
{
	data->draw.x = 0;
	data->draw.y = 0;
	data->draw.i = 1;
	data->draw.color = WHITE;
	data->draw.view = 0;
	data->draw.y_map = ft_lstsize(*data->map);
	data->draw.height = 1.0;
	data->draw.zoom = 1.0;
}

int	init_window(t_data data)
{
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			"fdf_42");
	if (data.win_ptr == NULL)
		return (free(data.win_ptr), 1);
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	init_params(&data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &key_pressed, &data);
	mlx_hook(data.win_ptr, DestroyNotify, Button1MotionMask, &close_win, &data);
	mlx_mouse_hook(data.win_ptr, &button_pressed, &data);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
