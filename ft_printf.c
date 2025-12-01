/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 21:29:55 by ryatan            #+#    #+#             */
/*   Updated: 2025/12/01 21:53:46 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

//static char	**ft_handle_new_line(char *c_format)
//{
//	char	**ret;
//
//	ret = ft_split(c_format, '\n');
//	return (ret);
//}

static void	ft_helper_types_1(va_list args, char f_map_specifier)
{
	char	*s;
	char	c;
	int		d;
	void	*p;

	if (f_map_specifier == 's')
	{
		s = va_arg(args, char *);
		ft_putstr_fd(s, 1);
	}
	else if (f_map_specifier == 'c')
	{
		c = (char)va_arg(args, int);
		ft_putchar_fd(c, 1);
	}
	else if (f_map_specifier == 'd' || f_map_specifier == 'i')
	{
		d = va_arg(args, int);
		ft_putnbr_fd(d, 1);
	}
	else if (f_map_specifier == 'p')
	{
		p = va_arg(args, void *);
		ft_putpointer(p);
	}
}

static void	ft_helper_types_2(va_list args, char f_map_specifier)
{
	unsigned int	u;
	unsigned int	x_lower;
	unsigned int	x_upper;

	if (f_map_specifier == 'u')
	{
		u = va_arg(args, unsigned int);
		ft_putunbr(u);
	}
	else if (f_map_specifier == 'x')
	{
		x_lower = va_arg(args, unsigned int);
		ft_puthex(x_lower, 'l');
	}
	else if (f_map_specifier == 'X')
	{
		x_upper = va_arg(args, unsigned int);
		ft_puthex(x_upper, 'u');
	}
}

int	ft_printf(const char *format, ...)
{
	char		**formatters;
	char		*c_format;
	va_list		args;
	t_format	f_map;
	int			i;

	c_format = (char *)format;
	formatters = ft_formatter_extract(c_format);
	va_start(args, format);
	i = 0;
	// check with each va_arg the type
	// va_arg(args, char*)
	while (formatters[i])
	{
		f_map = ft_formatter_properties(formatters[i]);
		if (f_map.specifier == 's' || f_map.specifier == 'c'
			|| f_map.specifier == 'p' || f_map.specifier == 'd'
			|| f_map.specifier == 'i')
			ft_helper_types_1(args, f_map.specifier);
		else
			ft_helper_types_2(args, f_map.specifier);
		i++;
	}
	va_end(args);
	return (1);
}
