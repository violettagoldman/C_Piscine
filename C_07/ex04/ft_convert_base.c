/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 01:09:23 by vgoldman          #+#    #+#             */
/*   Updated: 2019/07/13 23:40:19 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		base_check(char *base)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	if (!base[i] || !base[i + 1])
		return (0);
	while (base[i])
	{
		if (base[i] < 33 || base[i] > 127 || base[i] == '-' || base[i] == '+')
			return (0);
		j = i;
		while (base[j++])
			if (base[i] == base[j])
				return (0);
		i++;
	}
	return (1);
}

int		is_in_base(char c, char *base)
{
	unsigned int i;

	i = 0;
	while (base[i])
		if (c == base[i++])
			return (1);
	return (0);
}

int		ft_index(char c, char *base)
{
	unsigned int j;

	j = 0;
	while (c != base[j])
		j++;
	return (j);
}

long	ft_size(long nbr, long base_len)
{
	long	size;
	long	pow;

	size = 0;
	pow = 1;
	if (nbr <= 0)
	{
		size++;
		nbr = -nbr;
	}
	while (pow <= nbr)
	{
		pow *= base_len;
		size++;
	}
	return (size);
}
