/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 09:31:55 by vgoldman          #+#    #+#             */
/*   Updated: 2019/07/21 02:35:36 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list *current;
	t_list *temp;

	current = begin_list;
	if (begin_list == NULL)
		return ;
	while (current)
	{
		temp = current->next;
		free_fct(current->data);
		free(current);
		current = temp;
	}
}
