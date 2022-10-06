/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:02:44 by saguesse          #+#    #+#             */
/*   Updated: 2022/09/30 12:54:47 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_color(t_data *data)
{
	data->draw.i++;
	if (data->draw.i == 1)
		data->draw.color = RED;
	else if (data->draw.i == 2)
		data->draw.color = ORANGE;
	else if (data->draw.i == 3)
		data->draw.color = YELLOW;
	else if (data->draw.i == 4)
		data->draw.color = GREEN;
	else if (data->draw.i == 5)
		data->draw.color = BLUE;
	else if (data->draw.i == 6)
	{
		data->draw.color = PURPLE;
		data->draw.i = 0;
	}
}
