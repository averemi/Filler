/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:19:42 by averemii          #+#    #+#             */
/*   Updated: 2017/11/07 22:39:34 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		f_strlen(const char *str)
{
	static int count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t z;

	i = 0;
	j = 0;
	if (dst[0] == '\0' && src[0] == '\0')
		return (0);
	while (dst[i] != '\0' && i < dstsize)
		i++;
	z = i;
	if (dstsize > i)
	{
		while (j < (dstsize - z - 1))
		{
			dst[i++] = src[j++];
			dst[i] = '\0';
		}
	}
	return (z + f_strlen(src));
}
