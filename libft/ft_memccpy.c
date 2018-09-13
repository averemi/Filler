/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 22:50:05 by averemii          #+#    #+#             */
/*   Updated: 2017/11/06 15:58:06 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src,
			int c, size_t n)
{
	size_t					i;
	unsigned char			*dst1;
	const unsigned char		*src1;

	i = 0;
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	while (i < n)
	{
		if (src1[i] == (unsigned char)c)
		{
			dst1[i] = src1[i];
			return (dst1 + i + 1);
		}
		dst1[i] = src1[i];
		i++;
	}
	return (0);
}
