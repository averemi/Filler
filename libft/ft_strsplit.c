/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 23:32:12 by averemii          #+#    #+#             */
/*   Updated: 2017/11/15 23:32:14 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_words_count(char const *s, char c)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	if (s[0] != c && s[0] != '\0')
		count++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static size_t	ft_words_length(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static char		*ft_words_memory(char const *s, char c)
{
	char	*dst;
	size_t	index;

	index = 0;
	dst = (char *)malloc(sizeof(char *) * (ft_words_length(s, c) + 1));
	if (!dst)
		return (NULL);
	while (s[index] != c && s[index] != '\0')
	{
		dst[index] = s[index];
		index++;
	}
	dst[index] = '\0';
	return (dst);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (0);
	array = (char **)malloc(sizeof(char *) * (ft_words_count(s, c) + 1));
	if (!array)
		return (0);
	if (s[0] != c)
		array[i++] = ft_words_memory(s, c);
	j++;
	while (s[j - 1] != '\0')
	{
		if (s[j - 1] == c && s[j] != c && s[j] != '\0')
			array[i++] = ft_words_memory(s + j, c);
		j++;
	}
	if (s[0] == '\0')
		i = 0;
	array[i] = NULL;
	return (array);
}
