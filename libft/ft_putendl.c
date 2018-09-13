/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 01:26:46 by averemii          #+#    #+#             */
/*   Updated: 2017/11/16 01:26:48 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	int index;

	if (s)
	{
		index = 0;
		while (s[index] != '\0')
		{
			ft_putchar(s[index]);
			index++;
		}
		ft_putchar('\n');
	}
}
