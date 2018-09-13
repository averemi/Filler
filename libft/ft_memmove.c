/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:53:50 by averemii          #+#    #+#             */
/*   Updated: 2017/11/06 15:55:56 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int					i;
	unsigned char		*dst1;
	const unsigned char	*src1;

	i = 0;
	if (!dst && !src)
		return (NULL);
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	if (src1 < dst1)
	{
		i = len - 1;
		while (i >= 0)
		{
			dst1[i] = src1[i];
			i--;
		}
		return (dst1);
	}
	return (ft_memcpy(dst, src, len));
}
