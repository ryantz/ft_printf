/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter_validate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 14:07:35 by ryatan            #+#    #+#             */
/*   Updated: 2025/12/01 22:47:07 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_initialize_formatter_map(t_format *f_map)
{
	f_map->minus_flag = 0;
	f_map->zero_flag = 0;
	f_map->hash_flag = 0;
	f_map->plus_flag = 0;
	f_map->space_flag = 0;
	f_map->width = 0;
	f_map->precision = 0;
	f_map->specifier = 0;
}

// cspdiuxX%
static void ft_formatter_correction(t_format *f_map)
{
	if (f_map->specifier == 'c' || f_map->specifier == 's'
		|| f_map->specifier == 'p' || f_map->specifier == '%')
	{
		f_map->zero_flag = 0;
		f_map->hash_flag = 0;
		f_map->plus_flag = 0;
		f_map->space_flag = 0;
	}
	else if (f_map->specifier == 'd' || f_map->specifier == 'i')
		f_map->hash_flag = 0;
	else if (f_map->specifier == 'x' || f_map->specifier == 'X')
	{
		f_map->plus_flag = 0;
		f_map->space_flag = 0;
	}
	else if (f_map->specifier == 'u')
	{
		f_map->hash_flag = 0;
		f_map->plus_flag = 0;
		f_map->space_flag = 0;
	}
}

// % [flags] [width] [.precision] [length] specifier 
t_format ft_formatter_properties(char *formatter)
{
	t_format	f_map;
	int			flag;
	int			width;
	int			precision;
	int			specifier;

	ft_initialize_formatter_map(&f_map);
	flag = ft_hasflag(&formatter, &f_map);
	width = ft_haswidth(&formatter, &f_map);
	precision = ft_hasprecision(&formatter, &f_map);
	specifier = ft_hasspecifier(&formatter, &f_map);
	ft_formatter_correction(&f_map);
	return (f_map);
}
