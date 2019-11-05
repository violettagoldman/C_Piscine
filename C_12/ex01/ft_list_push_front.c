/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 09:06:43 by vgoldman          #+#    #+#             */
/*   Updated: 2019/07/20 09:29:17 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *current;

	if (*begin_list)
	{
		current = ft_create_elem(data);
		current->next = *begin_list;
		*begin_list = current;
	}
	else
		*begin_list = ft_create_elem(data);
}
