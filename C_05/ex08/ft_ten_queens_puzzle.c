/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 00:00:56 by vgoldman          #+#    #+#             */
/*   Updated: 2019/07/14 00:01:31 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check(int r, char c, char *list)
{
	int i;

	i = 0;
	while (i < c)
	{
		if (r == list[i] - '0' || r - list[i] + '0' == c - i ||
				r - list[i] + '0' == i - c)
			return (0);
		i++;
	}
	return (1);
}

void	funk(int c, char *list, int *count)
{
	int r;

	if (c > 9)
	{
		write(1, list, 10);
		write(1, "\n", 1);
		*count += 1;
	}
	r = 0;
	while (r < 10)
	{
		if (check(r, c, list))
		{
			list[c] = r + '0';
			funk(c + 1, list, count);
		}
		r++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	int		count_value;
	char	list[10];
	int		c;

	count_value = 0;
	c = 0;
	funk(c, list, &count_value);
	return (count_value);
}

int		main(void)
{
	ft_ten_queens_puzzle();
}
