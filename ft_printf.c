/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 21:29:55 by ryatan            #+#    #+#             */
/*   Updated: 2025/11/30 17:25:46 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	**ft_handle_new_line(char *c_format)
{
	char	**ret;

	ret = ft_split(c_format, '\n');
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	char	*c_format;

	c_format = (char *)format;
	return (1);
}
