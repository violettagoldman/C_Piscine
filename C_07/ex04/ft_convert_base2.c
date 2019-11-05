/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 01:59:55 by vgoldman          #+#    #+#             */
/*   Updated: 2019/07/11 22:39:45 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str);
int		base_check(char *base);
int		is_in_base(char c, char *base);
int		ft_index(char c, char *base);
long	ft_size(long nbr, long base_len);

long	ft_atoi_base(char *str, char *base)
{
	unsigned long	i;
	int				sign;
	unsigned long	nb;
	unsigned long	base_len;

	i = 0;
	sign = 1;
	nb = 0;
	base_len = ft_strlen(base);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
		sign *= 44 - str[i++];
	while (str[i] && is_in_base(str[i], base))
	{
		nb = nb * base_len + ft_index(str[i], base);
		i++;
	}
	return (nb * sign);
}

char	*ft_convert_decimal_base(long nbr, char *base)
{
	long	base_len;
	char	*res;
	long	size;

	base_len = ft_strlen(base);
	base_len = ft_strlen(base);
	size = ft_size(nbr, base_len);
	res = malloc(sizeof(int) * (size));
	if (nbr < 0)
	{
		res[0] = '-';
		nbr = -nbr;
	}
	res[size--] = '\0';
	while (nbr >= base_len)
	{
		res[size--] = base[nbr % base_len];
		nbr /= base_len;
	}
	res[size--] = base[nbr % base_len];
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char *res;

	if (!base_check(base_from) || !base_check(base_to))
		return (0);
	res = ft_convert_decimal_base(ft_atoi_base(nbr, base_from), base_to);
	return (res);
}
