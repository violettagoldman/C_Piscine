/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 09:52:05 by vgoldman          #+#    #+#             */
/*   Updated: 2019/07/21 02:32:25 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	swap(void **a, void **b)
{
	void *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list *current;
	t_list *next;

	current = *begin_list;
	if (*begin_list == NULL || (*begin_list)->next == NULL)
		current = *begin_list;
	while (current)
	{
		next = current->next;
		while (next)
		{
			if (cmp(current->data, next->data) > 0)
				swap(&(current->data), &(next->data));
			next = next->next;
		}
		current = current->next;
	}
}
