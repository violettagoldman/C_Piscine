/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 19:09:46 by vgoldman          #+#    #+#             */
/*   Updated: 2019/07/09 10:12:26 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long long		negative(long long nb)
{
	char		c;

	c = '-';
	if (nb < 0)
	{
		write(1, &c, 1);
		return (nb * (-1));
	}
	return (nb);
}

int				check_base(char *base)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j] || base[j] == ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void			nb_not_zero(int nbr)
{
	char		c;

	c = '0';
	if (nbr == 0)
		write(1, &c, 1);
}

int				length_base(char *base)
{
	int			len_base;

	len_base = 0;
	while (base[len_base])
		len_base++;
	return (len_base);
}

void			ft_putnbr_base(int nbr, char *base)
{
	int			len_base;
	int			result[100];
	int			i;
	long long	my_nb;

	len_base = 0;
	i = 0;
	my_nb = (long long)nbr;
	nb_not_zero(my_nb);
	if (check_base(base))
	{
		my_nb = negative(my_nb);
		len_base = length_base(base);
		while (my_nb)
		{
			result[i] = my_nb % len_base;
			my_nb = my_nb / len_base;
			i++;
		}
		while (--i >= 0)
			write(1, &(base[result[i]]), 1);
	}
}
