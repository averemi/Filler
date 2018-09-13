/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:01:18 by averemii          #+#    #+#             */
/*   Updated: 2017/11/14 17:01:24 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t		index;
	char		*dst;

	index = 0;
	if (s && f)
	{
		dst = (char *)malloc(sizeof(*dst) * (ft_strlen(s) + 1));
		if (dst)
		{
			while (*s != '\0')
				dst[index++] = f(*(s++));
			dst[index] = '\0';
			return (dst);
		}
	}
	return (0);
}
