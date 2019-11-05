/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:50:14 by vgoldman          #+#    #+#             */
/*   Updated: 2019/07/16 15:59:00 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_long_gen(int size, char **strs, char *sep)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < size)
	{
		count += ft_strlen(strs[i]);
		i++;
	}
	count += ft_strlen(sep) * (size - 1);
	return (count);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		i;

	i = 0;
	if (size == 0)
	{
		res = malloc(sizeof(char));
		res[0] = '\0';
		return (res);
	}
	if (!(res = malloc(sizeof(char) * (ft_long_gen(size, strs, sep) + 1))))
		return (NULL);
	*res = '\0';
	while (i < size)
	{
		res = ft_strcat(res, strs[i]);
		i++;
		if (i < size)
			res = ft_strcat(res, sep);
	}
	return (res);
}
