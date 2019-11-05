/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:12:47 by vgoldman          #+#    #+#             */
/*   Updated: 2019/07/15 22:36:24 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int delta;

	i = 0;
	delta = max - min;
	if (delta <= 0)
	{
		*range = NULL;
		return (0);
	}
	*range = NULL;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(sizeof(int) * delta);
	if (*range == NULL)
		return (-1);
	while (i < max - min)
	{
		(*range)[i] = i + min;
		i++;
	}
	return (delta);
}
