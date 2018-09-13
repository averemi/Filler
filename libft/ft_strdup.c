/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 21:03:10 by averemii          #+#    #+#             */
/*   Updated: 2017/11/06 21:08:23 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		index;

	index = 0;
	while (src[index] != '\0')
		index++;
	dest = (char *)malloc(sizeof(*dest) * (index + 1));
	if (!dest)
		return (NULL);
	dest[index] = '\0';
	while (index >= 0)
	{
		dest[index] = src[index];
		index--;
	}
	return (dest);
}
