/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 07:46:52 by vgoldman          #+#    #+#             */
/*   Updated: 2019/07/14 13:49:42 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_stock_str.h"

int						ft_len(char *str)
{
	int					i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char					*ft_strdup(char *src)
{
	char				*str;
	int					len;
	int					i;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	str = (char*)malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

struct s_stock_str		*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*res;

	i = 0;
	if (!(res = malloc((ac + 1) * sizeof(struct s_stock_str))))
		return (NULL);
	while (i < ac)
	{
		res[i].size = ft_len(av[i]);
		res[i].str = av[i];
		res[i].copy = ft_strdup(av[i]);
		i++;
	}
	res[i].str = NULL;
	return (res);
}
