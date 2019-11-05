/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 12:22:55 by vgoldman          #+#    #+#             */
/*   Updated: 2019/07/03 13:22:45 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	comma_space(int i, int j, int k)
{
	if (!(i == 7 && j == 8 && k == 9))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (i <= 9)
	{
		j = i + 1;
		while (j <= 9)
		{
			k = j + 1;
			while (k <= 9)
			{
				ft_putchar(48 + i);
				ft_putchar(48 + j);
				ft_putchar(48 + k);
				comma_space(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}
