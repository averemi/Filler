/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:03:29 by averemii          #+#    #+#             */
/*   Updated: 2017/11/08 22:19:29 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t i;
	size_t f;
	size_t z;

	i = 0;
	if (to_find[0] == '\0')
		return ((char*)str);
	while (i < len && str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			z = i;
			f = 0;
			while ((str[i] == to_find[f]) && (str[i] != '\0') && (i < len))
			{
				i++;
				f++;
				if (to_find[f] == '\0')
					return ((char*)(str + z));
			}
			i = z;
		}
		i++;
	}
	return (0);
}
