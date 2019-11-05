/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:05:47 by vgoldman          #+#    #+#             */
/*   Updated: 2019/07/18 00:48:46 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

int		do_op(int value1, char *op, int value2)
{
	int		i;
	char	*operators[5];
	int		(*f[5])(int, int);

	i = 0;
	operators[0] = "+";
	operators[1] = "-";
	operators[2] = "*";
	operators[3] = "/";
	operators[4] = "%";
	f[0] = &sum;
	f[1] = &sub;
	f[2] = &mult;
	f[3] = &div;
	f[4] = &mod;
	while (i < 5)
	{
		if (!ft_strcmp(op, operators[i]))
			return (f[i](value1, value2));
		i++;
	}
	return (0);
}

int		check(int argc, char **argv)
{
	int v1;
	int v2;

	v1 = ft_atoi(argv[1]);
	v2 = ft_atoi(argv[3]);
	(void)argc;
	if (!ft_strcmp(argv[2], "/") && v2 == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	if (!ft_strcmp(argv[2], "%") && v2 == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	if (ft_strcmp(argv[2], "%") != 0 && ft_strcmp(argv[2], "/") != 0 &&
		ft_strcmp(argv[2], "+") != 0 && ft_strcmp(argv[2], "-") != 0 &&
		ft_strcmp(argv[2], "*") != 0)
	{
		write(1, "0\n", 2);
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int v1;
	int v2;
	int result;

	if (argc != 4)
		return (0);
	v1 = ft_atoi(argv[1]);
	v2 = ft_atoi(argv[3]);
	if (v1 == 0 && v2 == 0)
	{
		write(1, "0\n", 2);
		return (0);
	}
	if (!(check(argc, argv)))
		return (0);
	result = do_op(v1, argv[2], v2);
	ft_putnbr(result);
	write(1, "\n", 1);
	return (0);
}
