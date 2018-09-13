/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 21:54:04 by averemii          #+#    #+#             */
/*   Updated: 2017/11/15 21:54:06 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	count;
	char	*dst;

	i = 0;
	count = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = ft_strlen(s);
	if (i == j)
		return (ft_strnew(0));
	while ((s[j - 1] == ' ' || s[j - 1] == '\n' || s[j - 1] == '\t')
		&& j > 0)
		j--;
	dst = ft_memalloc(j - i + 1);
	if (!dst)
		return (NULL);
	while (i < j)
		dst[count++] = s[i++];
	dst[count] = '\0';
	return (dst);
}
