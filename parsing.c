/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 10:10:23 by saguesse          #+#    #+#             */
/*   Updated: 2022/10/05 17:05:48 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	split_map(char *s, t_list **map, int x, int i)
{
	char	**line;
	t_list	*new;
	int		*nbr;

	line = ft_split(s, ' ');
	if (!line)
		return (1);
	while (line[x])
		x++;
	nbr = malloc(sizeof(nbr) * x);
	if (!nbr)
		return (1);
	while (i < x)
	{
		nbr[i] = ft_atoi(line[i]);
		free(line[i]);
		i++;
	}
	free(line);
	new = ft_lstnew(nbr, x);
	if (!new)
		return (1);
	ft_lstadd_back(map, new);
	return (0);
}

int	count_lines(char *file)
{
	int		fd;
	char	*line;
	t_list	*map;
	t_data	data;

	map = NULL;
	data.map = &map;
	fd = open(file, O_RDONLY);
	if (fd < 2 || fd > 1024)
		return (ft_printf("open() error\n"), 1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (split_map(line, data.map, 0, 0) == 1)
			break ;
		free(line);
	}
	if (close(fd) == -1)
		ft_printf("close() error\n");
	init_window(data);
	return (0);
}
