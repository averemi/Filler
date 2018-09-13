/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strntrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 02:30:30 by averemii          #+#    #+#             */
/*   Updated: 2017/11/19 02:30:32 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char static		*ft_strntrimstr(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	count;
	char	*dst;

	i = 0;
	count = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = ft_strlen(s);
	if (i == j)
		return (ft_strnew(0));
	while ((s[j - 1] == ' ' || s[j - 1] == '\n' || s[j - 1] == '\t') && j > 0)
		j--;
	dst = ft_memalloc(j - i + 1);
	if (!dst)
		return (NULL);
	while (i < j)
		dst[count++] = s[i++];
	dst[count] = '\0';
	return (dst);
}

char static		*ft_strntrimn(char const *s, size_t n)
{
	size_t	i;
	size_t	count;
	char	*dst;

	i = 0;
	count = 0;
	while ((i < n) && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	if (i == n)
		return (ft_strnew(0));
	while ((s[n - 1] == ' ' || s[n - 1] == '\n' || s[n - 1] == '\t') && n > 0)
		n--;
	dst = ft_memalloc(n - i + 1);
	if (!dst)
		return (NULL);
	while (i < n)
		dst[count++] = s[i++];
	dst[count] = '\0';
	return (dst);
}

char			*ft_strntrim(char const *s, size_t n)
{
	size_t	i;
	size_t	count;
	char	*dst;

	i = 0;
	count = 0;
	if (s && i < n)
	{
		if (n <= ft_strlen(s))
			dst = ft_strntrimn(s, n);
		if (n > ft_strlen(s))
			dst = ft_strntrimstr(s);
		return (dst);
	}
	return (NULL);
}
