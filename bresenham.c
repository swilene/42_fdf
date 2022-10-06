/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:09:56 by saguesse          #+#    #+#             */
/*   Updated: 2022/10/05 17:25:24 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_data *data, int err)
{
	int	e2;

	while (1)
	{
		if (data->coord.x1 < WIN_WIDTH && data->coord.x1 >= 0
			&& data->coord.y1 < WIN_HEIGHT && data->coord.y1 >= 0)
			img_pix_put(&data->img, data->coord.x1, data->coord.y1,
				data->draw.color);
		e2 = 2 * err;
		if (e2 >= data->coord.dy)
		{
			if (data->coord.x1 == data->coord.x2)
				break ;
			err += data->coord.dy;
			data->coord.x1 += data->coord.sx;
		}
		if (e2 <= data->coord.dx)
		{
			if (data->coord.y1 == data->coord.y2)
				break ;
			err += data->coord.dx;
			data->coord.y1 += data->coord.sy;
		}
	}
}

void	coeff_dir(t_data *data)
{
	if (data->coord.x1 < data->coord.x2)
		data->coord.sx = 1;
	else
		data->coord.sx = -1;
	if (data->coord.y1 < data->coord.y2)
		data->coord.sy = 1;
	else
		data->coord.sy = -1;
	bresenham(data, data->coord.dx + data->coord.dy);
}

void	columns(t_data *data)
{
	t_list	*start;
	t_list	*end;
	int		i;

	start = *data->map;
	end = (*data->map)->next;
	while (end)
	{
		i = 0;
		while (i < start->x_map)
		{
			data->coord.x1 = start->x_screen[i] + data->draw.x;
			data->coord.y1 = start->y_screen[i] + data->draw.y;
			data->coord.x2 = end->x_screen[i] + data->draw.x;
			data->coord.y2 = end->y_screen[i] + data->draw.y;
			data->coord.dx = abs(data->coord.x2 - data->coord.x1);
			data->coord.dy = -abs(data->coord.y2 - data->coord.y1);
			coeff_dir(data);
			i++;
		}
		start = end;
		end = end->next;
	}
}

void	lines(t_data *data)
{
	t_list	*tmp;
	int		i;

	tmp = *data->map;
	while (tmp)
	{
		i = 0;
		while (i < tmp->x_map - 1)
		{
			data->coord.x1 = tmp->x_screen[i] + data->draw.x;
			data->coord.y1 = tmp->y_screen[i] + data->draw.y;
			data->coord.x2 = tmp->x_screen[i + 1] + data->draw.x;
			data->coord.y2 = tmp->y_screen[i + 1] + data->draw.y;
			data->coord.dx = abs(data->coord.x2 - data->coord.x1);
			data->coord.dy = -abs(data->coord.y2 - data->coord.y1);
			coeff_dir(data);
			i++;
		}
		tmp = tmp->next;
	}
}
