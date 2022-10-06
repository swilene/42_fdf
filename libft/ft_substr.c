/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:31:57 by saguesse          #+#    #+#             */
/*   Updated: 2022/09/08 15:39:37 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (start > ft_strlen(s))
	{
		str = (char *)malloc(sizeof(*str) * 1);
		if (!str)
			return (NULL);
		return (str[i] = '\0', str);
	}
	else if (len > (ft_strlen(s) - start))
		str = (char *)malloc(sizeof(*str) * (ft_strlen(s) - start) + 1);
	else
		str = (char *)malloc(sizeof(*str) * len + 1);
	if (!str)
		return (NULL);
	while (i < len && s[start])
	{
		str[i] = s[start];
		i++;
		start++;
	}
	return (str[i] = '\0', str);
}
