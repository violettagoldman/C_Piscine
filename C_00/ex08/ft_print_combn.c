/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 17:18:29 by vgoldman          #+#    #+#             */
/*   Updated: 2019/07/04 17:36:16 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	increase(int start, char arr[], int position, int size)
{
	int i;

	i = start + 1;
	if (position == size)
	{
		arr[position] = '\0';
		write(1, arr, size);
		if (arr[0] != '9' - size + 1)
			write(1, ", ", 2);
	}
	while (i <= 10)
	{
		arr[position] = '0' + i - 1;
		increase(i, arr, position + 1, size);
		i++;
	}
}

void	ft_print_combn(int n)
{
	char arr[n + 1];

	increase(0, arr, 0, n);
}
