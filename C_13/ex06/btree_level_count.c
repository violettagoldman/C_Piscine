/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 10:02:31 by vgoldman          #+#    #+#             */
/*   Updated: 2019/07/22 09:44:09 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	cmp(int left, int right)
{
	if (left > right)
		return (left);
	else
		return (right);
}

int	btree_level_count(t_btree *root)
{
	if (!root)
		return (0);
	return (1 + cmp(btree_level_count(root->left),
				btree_level_count(root->right)));
}
