/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:30:53 by ryatan            #+#    #+#             */
/*   Updated: 2025/12/02 07:27:41 by ryatan           ###   ########.fr       */
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
	char	specifier;
}			t_format;

//printing fn
void	ft_puthex(unsigned int in, char casing);
void	ft_putpointer(void *ptr);
void	ft_putunbr(unsigned int nb);

// functions for formatter
char		**ft_formatter_extract(char *c_format);
void		ft_initialize_formatter_map(t_format *formatter_map);
t_format	ft_formatter_properties(char *formatter);

// formatter translators
char	*ft_formatter_translate_s(t_format *f_map, char *input);

// formatter checkers
int			ft_hasflag(char **formatter, t_format *formatter_map);
int			ft_haswidth(char **formatter, t_format *formatter_map);
int			ft_hasprecision(char **formatter, t_format *formatter_map);
int			ft_hasspecifier(char **formatter, t_format *formatter_map);

// main printf
int			ft_printf(const char *format, ...);

#endif
