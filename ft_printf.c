/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 21:29:55 by ryatan            #+#    #+#             */
/*   Updated: 2025/11/28 22:57:55 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	char	*c_format;

	c_format = (char *)format;
	ft_putstr_fd(c_format, 1);
	return (1);
}
