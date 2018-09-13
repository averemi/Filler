/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:25:54 by averemii          #+#    #+#             */
/*   Updated: 2017/11/13 16:25:57 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*dst;
	size_t	index;

	index = 0;
	dst = (char *)malloc(sizeof(*dst) * size);
	if (!dst)
		return (NULL);
	while (index < size)
		dst[index++] = 0;
	return (dst);
}
