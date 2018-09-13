/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:39:06 by averemii          #+#    #+#             */
/*   Updated: 2018/03/01 15:39:07 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_make_null(t_map *map)
{
	map->z = 0;
	map->r = 0;
	map->t = 0;
}

int			ft_fit_figure(t_map *map)
{
	if (map->z >= map->count && map->r == 1 && map->t == 0)
		return (1);
	return (0);
}

void		ft_find_min(char *min, t_map *map)
{
	if (*min == -100)
		*min = map->d;
	else if (*min != -100 && map->d < *min)
		*min = map->d;
}

void		ft_find_distance(t_map *map, int i1, int j1)
{
	int		i;
	int		j;
	char	min;

	i = -1;
	min = -100;
	while (map->map[++i] && i <= map->mheight)
	{
		j = 0;
		while (map->map[i][j] && j <= map->mwidth && i <= map->mheight)
		{
			if (map->enemy[i][j] == 0)
				j++;
			else if (map->enemy[i][j] == 1)
			{
				map->d = (i - i1 < 0) ? (i1 - i) : (i - i1);
				map->d1 = (j1 - j < 0) ? (j - j1) : (j1 - j);
				map->d = map->d + map->d1;
				ft_find_min(&min, map);
				j++;
			}
		}
	}
	map->calc[i1][j1] = min;
}

void		ft_make_calc(t_map *map)
{
	int i;
	int j;

	map->d = -1;
	map->d1 = -1;
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			ft_find_distance(map, i, j);
			j++;
		}
		i++;
	}
}
