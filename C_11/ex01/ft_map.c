/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 00:20:12 by vgoldman          #+#    #+#             */
/*   Updated: 2019/07/18 02:09:15 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *res;

	i = 0;
	if (!(res = (int*)malloc(sizeof(int) * length)))
		return (NULL);
	while (i < length)
	{
		res[i] = f(tab[i]);
		i++;
	}
	return (res);
}
