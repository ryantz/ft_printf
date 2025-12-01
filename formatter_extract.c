/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter_extract.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 12:33:29 by ryatan            #+#    #+#             */
/*   Updated: 2025/12/01 22:09:49 by ryatan           ###   ########.fr       */
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
	while (c_format[i])
	{
		if (c_format[i] == '%')
			count++;
		i++;
	}
	return (count);
}

static char	*ft_allocate_inner(char *c_format, int *start, int *end)
{
	char	*charset;
	char	*format_inner_string;
	char	*start_ptr;
	char	*in_formatter;

	charset = "cspdiuxX0123456789-0.# +";

	start_ptr = ft_strchr(c_format + *start,'%');
	*start = (start_ptr - c_format) + 1;
	in_formatter = c_format + *start;
	while (*in_formatter && ft_strchr(charset, *in_formatter))
		in_formatter++;
	*end = in_formatter - c_format;
	format_inner_string = malloc(sizeof(char) * ((*end - *start) + 1));
	if (!format_inner_string)
		return (NULL);
	ft_memcpy(format_inner_string, c_format + *start, *end - *start);
	return (format_inner_string[*end - *start] = '\0', format_inner_string);
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
