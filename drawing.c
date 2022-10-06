/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:12:10 by saguesse          #+#    #+#             */
/*   Updated: 2022/10/05 17:28:02 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric_view(t_list *tmp, int x, int y, t_data *data)
{
	double	space;
	double	height;

	space = WIN_HEIGHT / tmp->x_map / 2 * data->draw.zoom;
	height = data->draw.height * (space / 4);
	tmp->x_screen[x] = (cos(M_PI / 6) * (x - y) * space + (WIN_WIDTH
				/ 2 - tmp->x_map / 2 * (cos(M_PI / 6) * space)))
		+ 0.5;
	tmp->y_screen[x] = (sin(M_PI / 6) * (x + y) * space + (WIN_HEIGHT
				/ 2 - data->draw.y_map / 2 * (sin(M_PI / 6) * space))
			- (tmp->line[x] * height)) + 0.5;
}

void	parallel_view(t_list *tmp, int x, t_data *data)
{
	double	space;
	double	height;

	space = WIN_HEIGHT / tmp->x_map / 2 * data->draw.zoom;
	height = data->draw.height * (space / 4);
	tmp->x_screen[x] = (x * space + (data->draw.y_map / 2) + (WIN_WIDTH / 2
				- data->draw.y_map / 2 * space)) + 0.5;
	tmp->y_screen[x] = ((WIN_HEIGHT / 2) - tmp->line[x] * height) + 0.5;
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	render_map(t_data *data)
{
	t_list	*tmp;
	int		x;
	int		y;

	tmp = *data->map;
	y = 0;
	while (tmp)
	{
		x = 0;
		while (x < tmp->x_map)
		{
			if (data->draw.view == 0)
				isometric_view(tmp, x, y, data);
			else
				parallel_view(tmp, x, data);
			x++;
		}
		y++;
		tmp = tmp->next;
	}
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_map(data);
	lines(data);
	columns(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img,
		0, 0);
	return (0);
}
