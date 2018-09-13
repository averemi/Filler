/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 20:24:20 by averemii          #+#    #+#             */
/*   Updated: 2017/11/20 20:24:21 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countif(char **tab, int (*f)(char*))
{
	int i;
	int count;

	if (tab && *tab && f)
	{
		i = 0;
		count = 0;
		while (tab[i] != NULL)
		{
			if (f(tab[i]))
				count++;
			i++;
		}
		return (count);
	}
	return (0);
}
