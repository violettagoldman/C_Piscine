/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:45:10 by vgoldman          #+#    #+#             */
/*   Updated: 2019/07/04 17:31:22 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	count_display(int nb)
{
	int dozen;
	int unit;

	if (nb > 9)
	{
		dozen = nb / 10;
		unit = nb % 10;
		ft_putchar(dozen + 48);
		ft_putchar(unit + 48);
	}
	else
	{
		ft_putchar('0');
		ft_putchar(nb + 48);
	}
}

void	ft_print_comb2(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i <= 99)
	{
		j = i + 1;
		while (j <= 99)
		{
			count_display(i);
			ft_putchar(' ');
			count_display(j);
			if (i < 98 || j < 99)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			j++;
		}
		i++;
	}
}
