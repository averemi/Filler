/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 16:38:33 by averemii          #+#    #+#             */
/*   Updated: 2017/11/05 19:50:27 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *ret;

	ret = (unsigned char *)b;
	while (len > 0)
	{
		ret[len - 1] = (unsigned char)c;
		len--;
	}
	return (ret);
}
