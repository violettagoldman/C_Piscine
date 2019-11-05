/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:57:47 by vgoldman          #+#    #+#             */
/*   Updated: 2019/07/04 18:41:18 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int i;
	int temp[size];

	i = 0;
	while (i < size)
	{
		temp[i] = tab[size - 1 - i];
		i++;
	}
	i = 0;
	while (i < size)
	{
		tab[i] = temp[i];
		i++;
	}
}