/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter_validate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 14:07:35 by ryatan            #+#    #+#             */
/*   Updated: 2025/12/01 08:40:49 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_initialize_formatter_map(t_format *formatter_map)
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

// % [flags] [width] [.precision] [length] specifier 
t_format	ft_formatter_properties(char *formatter)
{
	t_format	formatter_map;
	int			check_flag;
	int			flag;
	int			width;
	
	ft_initialize_formatter_map(&formatter_map);
	formatter++;
	check_flag = ft_hasflag(*formatter, &formatter_map);
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
