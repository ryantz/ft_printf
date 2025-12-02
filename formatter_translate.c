/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter_translate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 07:12:47 by ryatan            #+#    #+#             */
/*   Updated: 2025/12/02 07:54:35 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// only - left justify 
// width + precision 10.3 (10 spaces, display 3 chars)
char	*ft_formatter_translate_s(t_format *f_map, char *input)
{
	int		len;
	//int		minus_flag;
	int		precision;
	char	*translated;

	len = f_map->width;
	printf("len %d\n", len);
	//minus_flag = f_map->minus_flag;
	precision = f_map->precision;
	printf("precision %d\n", precision);
	translated = malloc(sizeof(char) * (len + 1));
	ft_memset(translated, ' ', (len - precision));
	ft_memcpy(translated + (len - precision), input, precision);
	translated[len] = '\0';
	return (translated);
}
