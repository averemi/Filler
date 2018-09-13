/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 21:22:17 by averemii          #+#    #+#             */
/*   Updated: 2017/11/06 21:24:39 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *to_find)
{
	int index;
	int f;
	int z;

	index = 0;
	if (to_find[0] == '\0')
		return ((char*)str);
	while (str[index])
	{
		if (str[index] == to_find[0])
		{
			z = index;
			f = 0;
			while ((str[index] == to_find[f]) && (str[index] != '\0'))
			{
				index++;
				f++;
				if (to_find[f] == '\0')
					return ((char*)(str + z));
			}
			index = z;
		}
		index++;
	}
	return (0);
}
