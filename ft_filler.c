/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 21:07:04 by averemii          #+#    #+#             */
/*   Updated: 2018/02/23 21:07:45 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_create_struct(t_map *map)
{
	map->me = '\0';
	map->against = '\0';
	map->against1 = '\0';
	map->map = NULL;
	map->piece = NULL;
	map->enemy = NULL;
	map->calc = NULL;
	map->mheight = 0;
	map->mwidth = 0;
	map->pheight = 0;
	map->pwidth = 0;
	map->x = 0;
	map->y = 0;
	map->d = -1;
	map->d1 = -1;
	map->count = 0;
	map->res = -100;
	map->z = 0;
	map->r = 0;
	map->t = 0;
}

int			ft_write_coord(t_map *map)
{
	ft_putnbr(map->x);
	write(1, " ", 1);
	ft_putnbr(map->y);
	write(1, "\n", 1);
	return (1);
}

void		ft_find_player(char c, t_map *map)
{
	if (c == '1')
		map->me = 'O';
	else
		map->me = 'X';
	if (map->me == 'O')
	{
		map->against = 'x';
		map->against1 = 'X';
	}
	if (map->me == 'X')
	{
		map->against = 'o';
		map->against1 = 'O';
	}
}

int			main(void)
{
	t_map	map;
	char	*line;
	int		fd;

	fd = 0;
	line = NULL;
	ft_create_struct(&map);
	get_next_line(fd, &line);
	ft_find_player(line[10], &map);
	free(line);
	while (get_next_line(fd, &line) > 0)
	{
		ft_read_map(&map, line, fd);
		ft_clone_map(&map);
		ft_make_calc(&map);
		ft_algorythm(&map);
	}
	return (0);
}
