/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 10:02:52 by vgoldman          #+#    #+#             */
/*   Updated: 2019/07/22 19:47:58 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int		cmp1(int left, int right)
{
	if (left > right)
		return (left);
	return (right);
}

int		btree_level_count1(t_btree *root)
{
	if (!root)
		return (0);
	return (1 + cmp1(btree_level_count1(root->left),
		btree_level_count1(root->right)));
}

void	helper(t_btree *root, int current_level, int level,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	if (!root)
		return ;
	if (level == current_level)
		applyf(root->item, current_level, 0);
	else
	{
		helper(root->left, current_level + 1, level, applyf);
		helper(root->right, current_level + 1, level, applyf);
	}
}

void	btree_apply_by_level(t_btree *root,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int i;

	i = 0;
	while (i < btree_level_count1(root))
	{
		helper(root, 0, i, applyf);
		i++;
	}
}
