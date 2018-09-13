/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:24:22 by averemii          #+#    #+#             */
/*   Updated: 2017/11/08 22:24:36 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long int	result;
	int					sign;
	size_t				i;

	result = 0;
	i = 0;
	sign = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign = -1;
	if ((str[i] == '-' || str[i] == '+') && (str[i + 1] >= 48
			&& str[i + 1] <= '9'))
		i++;
	while (str[i] >= 48 && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		if (result >= 9223372036854775807 && sign == 1)
			return (-1);
		else if (result > 9223372036854775807 && sign == -1)
			return (0);
		i++;
	}
	return ((int)(result * sign));
}
