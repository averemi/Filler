/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 20:26:42 by averemii          #+#    #+#             */
/*   Updated: 2017/11/05 20:36:36 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char *ret;

	if (n > 0)
	{
		ret = (unsigned char *)s;
		while (n > 0)
		{
			ret[n - 1] = 0;
			n--;
		}
	}
}