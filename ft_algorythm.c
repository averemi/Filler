/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorythm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:33:09 by averemii          #+#    #+#             */
/*   Updated: 2018/03/01 15:33:11 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int					ft_check_dots(t_map *map, int i, int j)
{
	struct s_row	count;

	ft_count_piece(map);
	count.a3 = i - 1;
	count.a1 = -1;
	ft_make_null(map);
	while (map->map[++count.a3] && map->piece[++count.a1])
	{
		count.a4 = j - 1;
		count.a2 = -1;
		while (map->piece[count.a1][++count.a2]
			&& map->map[count.a3][++count.a4])
		{
			if (map->map[count.a3][count.a4] == '.')
				map->z++;
			if ((map->map[count.a3][count.a4] == map->me)
				&& map->piece[count.a1][count.a2] == '*')
				map->r++;
			if ((map->map[count.a3][count.a4] == map->against
				|| map->map[count.a3][count.a4] == map->against1)
				&& map->piece[count.a1][count.a2] == '*')
				map->t++;
		}
	}
	return (ft_fit_figure(map));
}

int					ft_check_sum(t_map *map, int i, int j)
{
	int				n;
	int				m;
	int				res;

	res = 0;
	n = 0;
	while (map->piece[n])
	{
		m = 0;
		while (map->piece[n][m])
		{
			res = map->calc[n + i][m + j] + res;
			m++;
		}
		n++;
	}
	if (map->res == -100 || res < map->res)
	{
		map->res = res;
		return (1);
	}
	return (0);
}

void				ft_start_coord(t_map *map)
{
	map->res = -100;
	map->x = 0;
	map->y = 0;
}

int					ft_algorythm(t_map *map)
{
	int				i;
	int				j;

	i = -1;
	ft_start_coord(map);
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (i <= (map->mheight - map->pheight)
				&& j <= (map->mwidth - map->pwidth))
			{
				if (ft_check_dots(map, i, j))
				{
					if (ft_check_sum(map, i, j))
					{
						map->x = i;
						map->y = j;
					}
				}
			}
		}
	}
	return (ft_write_coord(map));
}
