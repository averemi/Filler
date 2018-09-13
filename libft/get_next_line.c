/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 19:39:52 by averemii          #+#    #+#             */
/*   Updated: 2017/12/15 19:39:55 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_find_the_line(char **line, t_list_fd *fd_lst)
{
	char *str;
	char *str2;

	if (!(str = ft_strchr(fd_lst->cont, '\n')))
		return (0);
	*str = '\0';
	str++;
	if (!(*line = ft_strdup(fd_lst->cont)))
		return (0);
	if (!(str2 = ft_memalloc(ft_strlen(str))))
		return (0);
	str2 = ft_strcpy(str2, (const char*)str);
	str = NULL;
	free(str);
	free(fd_lst->cont);
	fd_lst->cont = NULL;
	if (!(fd_lst->cont = ft_strdup(str2)))
		return (0);
	free(str2);
	str2 = NULL;
	return (1);
}

static char			*ft_strjoin_n_free(char *str0, char *str1)
{
	int		c;
	int		a;
	char	*str2;
	size_t	count;

	count = 0;
	a = 0;
	if (str0)
		count = ft_strlen(str0);
	if (!(str2 = (char *)ft_memalloc(1 + count + ft_strlen((const char*)str1))))
		return (0);
	if (str0)
	{
		c = 0;
		while (str0[c] != '\0')
			str2[a++] = str0[c++];
	}
	if (str1)
	{
		while (*str1 != '\0')
			str2[a++] = *str1++;
	}
	if (str0)
		ft_strdel(&str0);
	return (str2);
}

static int			ft_check_fd(t_list_fd **checkfd, int fd, char **line, int i)
{
	if (i == 2)
	{
		*line = NULL;
		return (1);
	}
	else if (i == 1)
	{
		*line = ft_strdup((*checkfd)->cont);
		ft_strdel(&(*checkfd)->cont);
		return (1);
	}
	else if (i == 0)
	{
		while (*checkfd)
		{
			if ((*checkfd)->fd == fd)
				return (1);
			*checkfd = (*checkfd)->next;
		}
	}
	return (0);
}

static t_list_fd	*ft_choose_fd(t_list_fd **fd_start, int fd)
{
	t_list_fd	*check_fd;
	t_list_fd	*fd_connect;

	fd_connect = *fd_start;
	if (!(*fd_start))
	{
		if (!(*fd_start = (t_list_fd *)malloc(sizeof(t_list_fd))))
			return (0);
		(*fd_start)->cont = NULL;
		(*fd_start)->next = NULL;
		(*fd_start)->fd = fd;
		return (*fd_start);
	}
	check_fd = *fd_start;
	if (ft_check_fd(&check_fd, fd, NULL, 0))
		return (check_fd);
	if (!(check_fd = (t_list_fd *)malloc(sizeof(t_list_fd))))
		return (0);
	(check_fd)->cont = NULL;
	(check_fd)->next = NULL;
	(check_fd)->fd = fd;
	while (fd_connect->next)
		fd_connect = fd_connect->next;
	fd_connect->next = check_fd;
	return (check_fd);
}

int					get_next_line(const int fd, char **line)
{
	t_list_fd			*fd_lst;
	static t_list_fd	*fd_start;

	if (!line || fd < 0 || BUFF_SIZE <= 0 || read(fd, fd_start->t, 0) < 0)
		return (-1);
	fd_lst = ft_choose_fd(&fd_start, fd);
	ft_bzero(fd_lst->t, 2);
	while ((fd_lst->ret = read(fd, fd_lst->t, 1)) > 0)
	{
		fd_lst->t[fd_lst->ret] = '\0';
		fd_lst->cont = ft_strjoin_n_free(fd_lst->cont, fd_lst->t);
		if (ft_find_the_line(line, fd_lst))
			return (ft_check_fd(NULL, 0, (char **)fd_lst->t, 2));
	}
	if (!((fd_lst->cont == NULL) || (*(fd_lst)->cont == 0)))
	{
		if (ft_find_the_line(line, fd_lst))
			return (ft_check_fd(NULL, 0, (char **)fd_lst->t, 2));
		return (ft_check_fd(&fd_lst, 0, line, 1));
	}
	return (0);
}
