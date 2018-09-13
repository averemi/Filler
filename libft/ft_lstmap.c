/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 01:33:52 by averemii          #+#    #+#             */
/*   Updated: 2017/11/19 01:33:54 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*cnew;

	if (lst && f)
	{
		new = f(lst);
		cnew = new;
		while (lst->next != NULL)
		{
			lst = lst->next;
			new->next = f(lst);
			if (!(new->next = f(lst)))
			{
				free(new);
				return (NULL);
			}
			new = new->next;
		}
		return (cnew);
	}
	return (NULL);
}
