/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 08:27:04 by ryatan            #+#    #+#             */
/*   Updated: 2025/12/01 08:49:44 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_hasflag(char c, t_format *formatter_map)
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

// use **formatter to pass by ref and increase pointer idx
int	ft_haswidth(char **formatter, t_format *formatter_map);
{
	char	*width_string;

	while (**formatter != '\0')
	{
		if (**formatter >= '0' && **formatter <= '9')
		{
			//TODO: how to push into a char then use atoi to change to int
		}
		**formatter++;
	}
	return (0);
}
