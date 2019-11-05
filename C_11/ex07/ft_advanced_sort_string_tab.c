/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 00:51:58 by vgoldman          #+#    #+#             */
/*   Updated: 2019/07/18 00:52:57 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	char	*key;
	int		end;

	end = 1;
	i = 0;
	while (tab[i + 1] != 0)
	{
		if (cmp(tab[i], tab[i + 1]) > 0)
		{
			key = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = key;
			end = 0;
		}
		i++;
	}
	if (!end)
		ft_advanced_sort_string_tab(tab, cmp);
}
