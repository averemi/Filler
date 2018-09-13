/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:44:00 by averemii          #+#    #+#             */
/*   Updated: 2017/11/14 18:44:02 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	char	*dst;

	index = 0;
	if (s)
	{
		dst = ft_strnew(len);
		if (!dst)
			return (NULL);
		while ((start < ft_strlen(s)) && (index < len))
			dst[index++] = s[start++];
		return (dst);
	}
	return (NULL);
}
