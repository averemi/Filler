/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 01:52:29 by averemii          #+#    #+#             */
/*   Updated: 2017/11/16 01:52:32 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int ar[10];
	int count;

	if (n == 0)
		ft_putchar_fd('0', fd);
	if (n < 0 && n > -2147483648)
	{
		ft_putchar_fd('-', fd);
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
		ft_putchar_fd('0' + ar[--count], fd);
	if (n == -2147483648)
	{
		ft_putnbr_fd(-214748364, fd);
		ft_putchar_fd('8', fd);
	}
}
