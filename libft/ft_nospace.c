/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nospace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:58:20 by averemii          #+#    #+#             */
/*   Updated: 2017/11/21 21:58:27 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_count(char const *s)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] != ' ' && s[i] != '\n' && s[i] != '\t' && s[i] != '\0')
		{
			i++;
			count++;
		}
		i++;
	}
	return (count);
}

char				*ft_nospace(char const *s)
{
	size_t		i;
	size_t		count;
	char		*dst;

	i = 0;
	if (s[0] != '\0')
	{
		count = ft_count(s);
		if (count == 0)
			return (NULL);
		dst = ft_memalloc(count + 1);
		if (!dst)
			return (NULL);
		count = 0;
		while (s[i] != '\0')
		{
			while (s[i] != ' ' && s[i] != '\n' && s[i] != '\t' && s[i] != '\0')
				dst[count++] = s[i++];
			i++;
		}
		return (dst);
	}
	return (NULL);
}
