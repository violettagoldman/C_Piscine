/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 12:45:36 by vgoldman          #+#    #+#             */
/*   Updated: 2019/07/07 10:03:14 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] - 'A' + 'a';
		i++;
	}
	return (str);
}

int		ft_str_is_alpha(char c)
{
	if (c == '\0')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z'))
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if ((i == 0 || ft_str_is_alpha(str[i - 1]) == 0) &&
				(str[i] <= 'z' && str[i] >= 'a'))
			str[i] -= 32;
		i++;
	}
	return (str);
}
