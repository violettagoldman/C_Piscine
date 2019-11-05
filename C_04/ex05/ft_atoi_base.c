/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 16:26:01 by vgoldman          #+#    #+#             */
/*   Updated: 2019/07/09 16:26:09 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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
	if (!base[i])
		return (0);
	while (base[i])
	{
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (0);
		j = i;
		while (base[j++])
			if (base[i] == base[j])
				return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if(!base_check(base))
		return;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= ft_strlen(base))
		ft_putnbr_base(nbr / ft_strlen(base), base);
	write(1, base + nbr % ft_strlen(base), 1);
}

int		ft_atoi_base(char *str, char *base)
{
	unsigned int	i;
	unsigned int	j;
	int				sign;
	unsigned int	nb;
	unsigned int	base_len;

	i = 0;
	sign = 1;
	nb = 0;
	base_len = ft_strlen(base);
	if (!base_check(base))
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = sign * -1;
	while (str[i])
	{
		
		j = 0;
		while (base[j] != str[i])
			j++;
		nb = nb * base_len + j;
		i++;
	}
	return (nb * sign);
}
