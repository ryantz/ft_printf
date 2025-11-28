/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:19:46 by ryatan            #+#    #+#             */
/*   Updated: 2025/11/27 18:19:20 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	ret = malloc(sizeof(char) * s_len + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	ret[s_len] = '\0';
	return (ret);
}

//int	main(void)
//{
//	char	*strmapi;
//	strmapi = ft_strmapi("abcdef", ft_test_fn);
//	printf("%s\n", strmapi);
//	return (0);
//}
