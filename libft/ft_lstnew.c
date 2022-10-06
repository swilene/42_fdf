/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 09:51:29 by saguesse          #+#    #+#             */
/*   Updated: 2022/09/23 10:40:48 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int *nbr, int x)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->line = nbr;
	head->x_map = x;
	head->x_screen = malloc(sizeof(head->x_screen) * x);
	if (!(head->x_screen))
		return (NULL);
	head->y_screen = malloc(sizeof(head->y_screen) * x);
	if (!(head->y_screen))
		return (NULL);
	head->next = NULL;
	return (head);
}
