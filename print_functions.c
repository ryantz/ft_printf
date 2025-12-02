/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:21:44 by ryatan            #+#    #+#             */
/*   Updated: 2025/12/02 07:33:15 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putunbr(unsigned int nb)
{
	unsigned long	lnb;
	char			cnb;

	lnb = nb;
	if (lnb <= 9)
	{
		cnb = lnb + '0';
		write(1, &cnb, 1);
	}
	else
	{
		ft_putunbr(lnb / 10);
		ft_putunbr(lnb % 10);
	}
}

void	ft_puthex(unsigned int in, char casing)
{
	unsigned long	l_in;
	char			*hex_range_upper;
	char			*hex_range_lower;
	char			c_in;

	l_in = in;
	hex_range_lower = "0123456789abcdef";
	hex_range_upper = "0123456789ABCDEF";
	if (l_in < 16)
	{
		if (casing == 'l')
			c_in = hex_range_lower[l_in];
		else if (casing == 'u')
			c_in = hex_range_upper[l_in];
		write(1, &c_in, 1);
	}
	else if (l_in >= 16)
	{
		ft_puthex(l_in / 16, casing);
		ft_puthex(l_in % 16, casing);
	}
}

static void	ft_puthex_long(unsigned long ptr)
{
	char			*hex_range;
	char			c_in;

	hex_range = "0123456789abcdef";
	if (ptr < 16)
	{
		c_in = hex_range[ptr];
		write(1, &c_in, 1);
	}
	else if (ptr >= 16)
	{
		ft_puthex_long(ptr / 16);
		ft_puthex_long(ptr % 16);
	}
}

void	ft_putpointer(void *ptr)
{
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	ft_puthex_long((unsigned long)ptr);
}
