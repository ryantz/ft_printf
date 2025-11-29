/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:30:53 by ryatan            #+#    #+#             */
/*   Updated: 2025/11/29 16:24:43 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

// test lib
#include <stdio.h>

typedef struct s_format
{
	char	flag;
	int		width;
	int		precision_flag;
	int		length;
	char	specifier;
}			t_format;

// functions for formatter
char	**ft_formatter_extract(char *c_format);

// main printf
char	**ft_handle_new_line(char *c_format);
int		ft_printf(const char *format, ...);

#endif
