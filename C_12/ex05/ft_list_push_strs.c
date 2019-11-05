/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 09:17:02 by vgoldman          #+#    #+#             */
/*   Updated: 2019/07/21 02:12:18 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *current;

	current = ft_create_elem(data);
	current->next = *begin_list;
	*begin_list = current;
}

t_list		*ft_list_push_strs(int size, char **strs)
{
	t_list	*new;
	int		i;

	new = NULL;
	i = 0;
	while (i < size)
	{
		ft_list_push_front(&new, strs[i]);
		i++;
	}
	return (new);
}
