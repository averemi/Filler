/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clone_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:32:55 by averemii          #+#    #+#             */
/*   Updated: 2018/03/01 15:32:57 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_malloc_map(t_map *map)
{
	map->enemy = (char **)malloc(sizeof(char *) * (map->mheight + 1));
	map->calc = (char **)malloc(sizeof(char *) * (map->mheight + 1));
}

void		ft_clone_map(t_map *map)
{
	int i;
	int j;

	i = -1;
	ft_malloc_map(map);
	while (map->map[++i])
	{
		j = -1;
		map->enemy[i] = (char *)malloc(sizeof(char) * (map->mwidth + 1));
		map->calc[i] = (char *)malloc(sizeof(char) * (map->mwidth + 1));
		while (map->map[i][++j])
		{
			if (map->map[i][j] == map->against
				|| map->map[i][j] == map->against1)
				map->enemy[i][j] = 1;
			else if (map->map[i][j] != map->against
				&& map->map[i][j] != map->against1)
				map->enemy[i][j] = 0;
			map->calc[i][j] = 0;
		}
		map->enemy[i][j] = '\0';
		map->calc[i][j] = '\0';
	}
	map->enemy[i] = NULL;
	map->calc[i] = NULL;
}

void		ft_count_piece(t_map *map)
{
	int i;
	int j;
	int z;

	i = 0;
	z = 0;
	while (map->piece[i])
	{
		j = 0;
		while (map->piece[i][j])
		{
			if (map->piece[i][j] == '*')
				z++;
			j++;
		}
		i++;
	}
	map->count = z - 1;
}
