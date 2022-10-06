/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:35:13 by saguesse          #+#    #+#             */
/*   Updated: 2022/10/05 15:26:20 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*check_file(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (len > ft_strlen(big))
		len = ft_strlen(big);
	if (little[j] == '\0')
		return ((char *)big);
	while (big[i] && little[j] && len > 0)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			if (little[j + 1] == '\0' && big[j + i + 1] == '\0')
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (check_file(argv[1], ".fdf", ft_strlen(argv[1])) == NULL)
			return (ft_printf("wrong file name\n"), 1);
		count_lines(argv[1]);
	}
	return (0);
}
