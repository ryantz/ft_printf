/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter_extract.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 12:33:29 by ryatan            #+#    #+#             */
/*   Updated: 2025/11/29 16:00:45 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// % [flags] [width] [.precision] [length] specifier 
// specifier can only be exactly 1
static int	ft_formatter_count(char *c_format)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (c_format[i++])
	{
		if (c_format[i] == '%')
			count++;
	}
	return (count);
}

static char	*ft_allocate_inner(char *c_format, int *start, int *end)
{
	char	*charset;
	char	*format_inner_string;
	int		i;
	int		j;

	charset = "cspdiuxX0123456789%-0.# +";
	while (c_format[*start] && c_format[*start] != '%')
		(*start)++;
	*end = *start;
	i = 0;
	while (charset[i++])
	{
		while (c_format[*end] && c_format[*end] == charset[i])
		{
			(*end)++;
			i = 0;
		}
	}
	format_inner_string = malloc(sizeof(char) * ((*end - *start) + 1));
	if (!format_inner_string)
		return (NULL);
	j = 0;
	while (*start < *end)
		format_inner_string[j++] = c_format[(*start)++];
	return (format_inner_string[j] = '\0', format_inner_string);
}

static void	ft_free_all(int formatter_sym_count, char **outer)
{
	while (formatter_sym_count--)
		free(outer[formatter_sym_count]);
	free(outer);
}

char	**ft_formatter_extract(char *c_format)
{
	char	**formatter_store;
	int		formatter_sym_count;
	int		start;
	int		end;
	int		j;

	formatter_sym_count = ft_formatter_count(c_format);
	formatter_store = malloc(sizeof(char *) * (formatter_sym_count + 1));
	if (!formatter_store)
		return (NULL);
	start = 0;
	end = 0;
	j = 0;
	while (j < formatter_sym_count)
	{
		formatter_store[j] = ft_allocate_inner(c_format, &start, &end);
		if (!formatter_store[j])
			return (ft_free_all(formatter_sym_count, formatter_store), NULL);
		j++;
	}
	formatter_store[j] = NULL;
	return (formatter_store);
}
