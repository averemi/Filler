/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 00:33:49 by averemii          #+#    #+#             */
/*   Updated: 2017/11/19 00:33:53 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;

	if (alst && *alst && del)
	{
		list = *alst;
		while (list)
		{
			del(list->content, list->content_size);
			free(list);
			list = list->next;
		}
		*alst = NULL;
	}
}
