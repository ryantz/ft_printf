/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 08:27:04 by ryatan            #+#    #+#             */
/*   Updated: 2025/12/01 19:04:49 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_hasflag(char **formatter, t_format *f_map)
{
	while (**formatter)
	{
		if (**formatter == '-')
			f_map->minus_flag = 1;
		else if (**formatter == '0')
			f_map->zero_flag = 1;
		else if (**formatter == '#')
			f_map->hash_flag = 1;
		else if (**formatter == '+')
			f_map->plus_flag = 1;
		else if (**formatter == ' ')
			f_map->space_flag = 1;
		else
			return (0);
		(*formatter)++;
	}
	return (1);
}

// use **formatter to pass by ref and increase pointer idx
int	ft_haswidth(char **formatter, t_format *f_map)
{
	char	*width_string;
	int		start;
	int		end;
	int		width_length;
	int		i;

	if (!(**formatter >= '0' && **formatter <= '9'))
		return (0);
	start = 0;
	end = 0;
	i = 0;
	while ((*formatter)[i++] && ((*formatter)[i] >= '0'
			&& (*formatter)[i] <= '9'))
		end++;
	width_string = malloc(sizeof(char) * ((end - start + 1) + 1));
	if (!width_string)
		return (0);
	ft_memcpy(width_string, *formatter, (end - start + 1));
	width_string[end + 1] = '\0';
	width_length = ft_atoi(width_string);
	f_map->width = width_length;
	*formatter += end + 1;
	return (free(width_string), width_length);
}

int	ft_hasprecision(char **formatter, t_format *f_map)
{
	char	*precision_string;
	int		start;
	int		end;
	int		precision_value;
	int		i;

	if (**formatter != '.')
		return (0);
	(*formatter)++;
	start = 0;
	end = 0;
	i = 0;
	while ((*formatter)[i++] && ((*formatter)[i] >= '0'
			&& (*formatter)[i] <= '9'))
		end++;
	precision_string = malloc(sizeof(char) * ((end - start) + 1));
	if (!precision_string)
		return (0);
	ft_memcpy(precision_string, *formatter, (end - start));
	precision_string[end + 1] = '\0';
	precision_value = ft_atoi(precision_string);
	f_map->precision = precision_value;
	*formatter += end + 1;
	return (free(precision_string), precision_value);
}

int	ft_hasspecifier(char **formatter, t_format *f_map)
{
	char	*specifiers;
	int		i;

	specifiers = "cspdiuxX%";
	i = 0;
	while (specifiers[i])
	{
		if (**formatter == specifiers[i])
		{
			f_map->specifier = specifiers[i];
			(*formatter)++;
			return (1);
		}
		i++;
	}
	return (0);
}
