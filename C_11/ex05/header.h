/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 16:53:59 by vgoldman          #+#    #+#             */
/*   Updated: 2019/07/17 19:15:35 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>

int		ft_atoi(char *str);
int		ft_any(char **tab, int(*f)(char*));
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		sum(int a, int b);
int		sub(int a, int b);
int		mod(int a, int b);
int		div(int a, int b);
int		mult(int a, int b);
int		do_op(int value1, char *op, int value2);
int		ft_strcmp(char *s1, char *s2);
int		check(int argc, char **argv);
#endif
