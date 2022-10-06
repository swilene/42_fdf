/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dellist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:00:25 by saguesse          #+#    #+#             */
/*   Updated: 2022/09/25 14:57:20 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dellist(t_list **lst)
{
	t_list	*tmp;

	if ((*lst) == NULL)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->line);
		free((*lst)->x_screen);
		free((*lst)->y_screen);
		free(*lst);
		(*lst) = tmp;
	}
}
