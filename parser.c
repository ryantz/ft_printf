/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 08:06:24 by ryatan            #+#    #+#             */
/*   Updated: 2025/11/29 10:58:38 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// % [flags] [width] [.precision] [length] specifier
// specifier can only be exactly 1

int	ft_formatter_count(char *c_format)
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


char	*ft_formatter_extract(char *c_format)
{
	char	*charset;
	char	*flags;
	
	specifiers = "cspdiuxX%";
	flags = "-0.# +";
}
