/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 01:22:31 by averemii          #+#    #+#             */
/*   Updated: 2017/11/16 01:22:33 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int ar[10];
	int count;

	if (n == 0)
		ft_putchar('0');
	if (n < 0 && n > -2147483648)
	{
		ft_putchar('-');
		n = n * (-1);
	}
	count = 0;
	while (n > 0)
	{
		ar[count] = n % 10;
		n = n / 10;
		count++;
	}
	while (count > 0)
		ft_putchar('0' + ar[--count]);
	if (n == -2147483648)
	{
		ft_putnbr(-214748364);
		ft_putchar('8');
	}
}
