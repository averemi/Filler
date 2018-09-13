/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:33:28 by averemii          #+#    #+#             */
/*   Updated: 2017/11/17 15:33:30 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*newlist;
	void		*copy_content;

	newlist = (t_list*)malloc(sizeof(t_list));
	if (!newlist)
		return (NULL);
	if (!content || !content_size)
	{
		newlist->content = NULL;
		newlist->content_size = 0;
		newlist->next = NULL;
	}
	else
	{
		copy_content = (void*)malloc(sizeof(content_size));
		if (!copy_content)
		{
			free(newlist);
			return (NULL);
		}
		newlist->content = ft_memcpy(copy_content, content, content_size);
		newlist->content_size = content_size;
		newlist->next = NULL;
	}
	return (newlist);
}
