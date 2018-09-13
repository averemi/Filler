/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:45:29 by averemii          #+#    #+#             */
/*   Updated: 2017/11/14 17:45:31 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	unsigned int	count;
	char			*dst;

	index = 0;
	count = 0;
	if (s && f)
	{
		dst = (char *)malloc(sizeof(*dst) * (ft_strlen(s) + 1));
		if (dst)
		{
			while (*s != '\0')
				dst[index++] = f(count++, *(s++));
			dst[index] = '\0';
			return (dst);
		}
	}
	return (0);
}
