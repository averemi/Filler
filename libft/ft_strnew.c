/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:48:01 by averemii          #+#    #+#             */
/*   Updated: 2017/11/13 18:48:06 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*dst;
	size_t	index;

	index = 0;
	dst = (char *)malloc(sizeof(*dst) * (size + 1));
	if (!dst)
		return (NULL);
	while (index < size)
		dst[index++] = '\0';
	dst[index] = '\0';
	return (dst);
}
