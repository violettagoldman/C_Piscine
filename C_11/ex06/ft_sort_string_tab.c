/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 00:49:11 by vgoldman          #+#    #+#             */
/*   Updated: 2019/07/18 00:51:44 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	char	*key;
	int		end;

	end = 1;
	i = 0;
	if (tab == 0 || tab[0] == 0)
		return ;
	while (tab[i + 1] != 0)
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			key = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = key;
			end = 0;
		}
		i++;
	}
	if (!end)
		ft_sort_string_tab(tab);
}
