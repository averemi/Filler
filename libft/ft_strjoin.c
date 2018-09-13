/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 21:13:13 by averemii          #+#    #+#             */
/*   Updated: 2017/11/15 21:13:15 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	i;
	size_t	t;

	i = 0;
	if (s1 && s2)
	{
		t = ft_strlen(s1) + ft_strlen(s2);
		dst = ft_memalloc(t + 1);
		if (!dst)
			return (NULL);
		ft_strcpy(dst, s1);
		ft_strcat(dst, s2);
		return (dst);
	}
	return (NULL);
}
