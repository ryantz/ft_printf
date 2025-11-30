/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter_validate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 14:07:35 by ryatan            #+#    #+#             */
/*   Updated: 2025/11/30 23:50:42 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_initialize_formatter_map(t_format *formatter_map)
{
	formatter_map->minus_flag = 0;
	formatter_map->zero_flag = 0;
	formatter_map->hash_flag = 0;
	formatter_map->plus_flag = 0;
	formatter_map->space_flag = 0;
	formatter_map->width = 0;
	formatter_map->precision = 0;
	formatter_map->length = 0;
	formatter_map->specifier = 0;
}

int	ft_isflag(char c, t_format *formatter_map)
{
	if (c == '-')
		formatter_map->minus_flag = 1;
	else if (c == '0')
		formatter_map->zero_flag = 1;
	else if (c == '#')
		formatter_map->hash_flag = 1;
	else if (c == '+')
		formatter_map->plus_flag = 1;
	else if (c == ' ')
		formatter_map->space_flag = 1;
	else
		return (0);
	return (1);
}

// % [flags] [width] [.precision] [length] specifier 
t_format	*ft_formatter_properties(char *formatter)
{
	t_format	formatter_map;
	int			check_flag;
	int			flag;
	
	ft_initialize_formatter_map(&formatter_map);
	formatter++;
	check_flag = ft_isflag(*formatter, &formatter_map);
	formatter++;
	// check width
	// check precision
	// check length
	return (formatter_map);
}

char	*ft_map_translate(t_format formatter_map)
{
	char	*translated_string;

	return (translated_string);
}
