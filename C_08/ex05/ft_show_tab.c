/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 09:00:41 by vgoldman          #+#    #+#             */
/*   Updated: 2019/07/14 00:51:08 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_stock_str.h"

void				ft_putchar(char c)
{
	write(1, &c, 1);
}

void				ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void				ft_putnbr(int nb)
{
	long a;

	a = nb;
	if (a < 0)
	{
		ft_putchar('-');
		a = a * (-1);
	}
	if (a > 9)
	{
		ft_putnbr(a / 10);
		ft_putchar(a % 10 + '0');
	}
	else
		ft_putchar(a + '0');
}

void				ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	if (!par)
		return ;
	while (par[i].str != NULL)
	{
		ft_putstr(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		i++;
	}
}
