/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 09:14:38 by vgoldman          #+#    #+#             */
/*   Updated: 2019/07/21 09:29:39 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *current;

	current = *begin_list;
	if (current)
	{
		while (current->next)
			current = current->next;
		current->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}
