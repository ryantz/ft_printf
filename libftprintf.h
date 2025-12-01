/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:30:53 by ryatan            #+#    #+#             */
/*   Updated: 2025/12/01 08:29:37 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

// test lib
# include <stdio.h>

// formatter structure check
typedef struct s_format
{
	int		minus_flag;
	int		zero_flag;
	int		hash_flag;
	int		plus_flag;
	int		space_flag;
	int		width;
	int		precision;
	int		length;
	char	specifier;
}			t_format;

// functions for formatter
char	**ft_formatter_extract(char *c_format);

// formatter checkers
int	ft_hasflag(char c, t_format *formatter_map);

// main printf
char	**ft_handle_new_line(char *c_format);
int		ft_printf(const char *format, ...);

#endif
