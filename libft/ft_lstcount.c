/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:49:02 by averemii          #+#    #+#             */
/*   Updated: 2017/11/20 19:49:04 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstcount(t_list *begin_list)
{
	int count;

	count = 1;
	if (begin_list)
	{
		while (begin_list->next != NULL)
		{
			begin_list = begin_list->next;
			count++;
		}
		return (count);
	}
	return (0);
}
