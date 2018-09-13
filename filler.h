/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 21:04:39 by averemii          #+#    #+#             */
/*   Updated: 2018/02/23 21:04:47 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "./libft/libft.h"

typedef struct		s_map
{
	char			me;
	char			against;
	char			against1;
	char			**map;
	char			**piece;
	char			**enemy;
	char			**calc;
	int				mheight;
	int				mwidth;
	int				pheight;
	int				pwidth;
	int				x;
	int				y;
	int				count;
	char			d;
	char			d1;
	char			min;
	int				res;
	int				z;
	int				r;
	int				t;
}					t_map;

struct				s_row
{
	int				a1;
	int				a2;
	int				a3;
	int				a4;
};

void				ft_find_player(char c, t_map *map);
int					ft_write_coord(t_map *map);
void				ft_create_struct(t_map *map);
int					ft_check_dots(t_map *map, int i, int j);
int					ft_check_sum(t_map *map, int i, int j);
void				ft_start_coord(t_map *map);
int					ft_algorythm(t_map *map);
void				ft_make_null(t_map *map);
int					ft_fit_figure(t_map *map);
void				ft_find_min(char *min, t_map *map);
void				ft_find_distance(t_map *map, int i1, int j1);
void				ft_make_calc(t_map *map);
void				ft_clone_map(t_map *map);
void				ft_count_piece(t_map *map);
void				ft_find_piece_coord(char *line, t_map *map);
void				ft_find_map_coord(char *line, t_map *map);
void				ft_read_map(t_map *map, char *line, int fd);
void				ft_malloc_map(t_map *map);

#endif
