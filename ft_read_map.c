/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:32:42 by averemii          #+#    #+#             */
/*   Updated: 2018/03/01 15:32:46 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_find_piece_coord(char *line, t_map *map)
{
	char *s;

	s = line;
	while (!ft_isdigit(*s))
		s++;
	map->pheight = ft_atoi(s);
	while (ft_isdigit(*s))
		s++;
	map->pwidth = ft_atoi(s);
	map->piece = (char **)malloc(sizeof(char *) * (map->pheight + 1));
	free(line);
}

void	ft_find_map_coord(char *line, t_map *map)
{
	char *s;

	s = line;
	while (!ft_isdigit(*s))
		s++;
	map->mheight = ft_atoi(s);
	while (ft_isdigit(*s))
		s++;
	map->mwidth = ft_atoi(s);
	free(line);
}

void	ft_read_map(t_map *map, char *line, int fd)
{
	int		n;
	int		i;

	n = 0;
	i = 0;
	ft_find_map_coord(line, map);
	map->map = (char **)malloc(sizeof(char *) * (map->mheight + 1));
	get_next_line(fd, &line);
	free(line);
	while (n < map->mheight && (get_next_line(fd, &line) > 0))
	{
		map->map[n++] = ft_strdup(line + 4);
		free(line);
	}
	map->map[n] = NULL;
	n = 0;
	get_next_line(fd, &line);
	ft_find_piece_coord(line, map);
	while (n < map->pheight && (get_next_line(fd, &line) > 0))
	{
		map->piece[n++] = ft_strdup(line);
		free(line);
	}
	map->piece[n] = NULL;
}
