/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 09:45:23 by vgoldman          #+#    #+#             */
/*   Updated: 2019/07/21 10:36:24 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *))
{
	t_list *current;

	if (*begin_list)
	{
		if (cmp((*begin_list)->data, data_ref) == 0)
		{
			current = *begin_list;
			*begin_list = (*begin_list)->next;
			free_fct(current->data);
			free(current);
			ft_list_remove_if(begin_list, data_ref, cmp, free_fct);
		}
		else
			ft_list_remove_if(&(*begin_list)->next, data_ref, cmp, free_fct);
	}
}
