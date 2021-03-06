/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 00:07:02 by vgoldman          #+#    #+#             */
/*   Updated: 2019/07/14 00:07:07 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	rootmax;
	long	rootmin;
	long	root;
	long	n;

	rootmax = nb + 1;
	rootmin = 0;
	if (nb <= 3 && nb != 1)
		return (0);
	while (rootmax - rootmin > 1)
	{
		root = (rootmax + rootmin) / 2;
		n = root * root;
		if (n == nb)
			return (root);
		if (n > nb)
			rootmax = root;
		if (n < nb)
			rootmin = root;
	}
	return (root);
}

int	ft_is_prime(int nb)
{
	int i;

	i = 3;
	if (nb == 2)
		return (1);
	if (nb <= 1 || !(nb % 2))
		return (0);
	while (i <= ft_sqrt(nb))
	{
		if (!(nb % i))
			return (0);
		i += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int i;

	i = nb;
	if (nb <= 2)
		return (2);
	if (!(nb % 2))
		i++;
	while (!ft_is_prime(i))
		i += 2;
	return (i);
}
