/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:33:25 by averemii          #+#    #+#             */
/*   Updated: 2017/11/17 11:33:27 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(int n)
{
	int z;

	z = 0;
	while (n != 0)
	{
		n = n / 10;
		z++;
	}
	return (z);
}

static char		*ft_itoa_negative(int n)
{
	int		index;
	int		count;
	char	*ar1;
	char	*ar2;

	ar1 = NULL;
	ar2 = NULL;
	ar1 = ft_strnew(ft_count(n) + 1);
	if (!ar1)
		return (NULL);
	ar2 = ft_strnew(ft_count(n) + 1);
	if (!ar2)
		return (NULL);
	ar2[0] = '-';
	n = n * (-1);
	count = 0;
	while (n > 0)
	{
		ar1[count++] = (n % 10) + '0';
		n = n / 10;
	}
	index = 1;
	while (count > 0)
		ar2[index++] = ar1[--count];
	return (ar2);
}

static char		*ft_itoa_positive(int n)
{
	int		index;
	int		count;
	char	*ar1;
	char	*ar2;

	ar1 = NULL;
	ar2 = NULL;
	ar1 = ft_strnew(ft_count(n));
	if (!ar1)
		return (NULL);
	ar2 = ft_strnew(ft_count(n));
	if (!ar2)
		return (NULL);
	count = 0;
	while (n > 0)
	{
		ar1[count++] = (n % 10) + '0';
		n = n / 10;
	}
	index = 0;
	while (count > 0)
		ar2[index++] = ar1[--count];
	return (ar2);
}

char			*ft_itoa(int n)
{
	char	*ar2;

	ar2 = NULL;
	if (n == 0)
	{
		ar2 = ft_strnew(1);
		if (!ar2)
			return (NULL);
		ar2[0] = '0';
	}
	else if (n > 0)
		ar2 = ft_itoa_positive(n);
	else if (n < 0 && n > -2147483648)
		return (ft_itoa_negative(n));
	else if (n == -2147483648)
		ar2 = ft_strdup("-2147483648");
	return (ar2);
}
