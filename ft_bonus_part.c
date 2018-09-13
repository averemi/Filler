/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_part.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 21:10:10 by averemii          #+#    #+#             */
/*   Updated: 2018/03/01 21:10:13 by averemii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

void	ft_color_player(char *line)
{
	if (line[0] == '$')
	{
		if (line[10] == '1')
			printf("\x1B[32m" "%s\n" "\x1B[0m", line);
		else if (line[10] == '2')
			printf("\x1B[33m" "%s\n" "\x1B[0m", line);
	}
}

void	ft_color_map(char *line)
{
	int i;

	i = 0;
	if (line[0] >= '0' && line[0] <= '9')
	{
		while (line[i])
		{
			if (line[i] == 'O' || line[i] == 'o')
				printf("\x1B[32m" "%c" "\x1B[0m", line[i]);
			else if (line[i] == 'X' || line[i] == 'x')
				printf("\x1B[33m" "%c" "\x1B[0m", line[i]);
			else
				printf("%c", line[i]);
			i++;
		}
		printf("\n");
	}
}

int		ft_color_res(char *line)
{
	if (line[0] == '=')
	{
		if (line[0] == '=' && line[3] == 'O')
			printf("\x1B[32m" "%s\n" "\x1B[0m", line);
		get_next_line(0, &line);
		if (line[0] == '=' && line[3] == 'X')
			printf("\x1B[33m" "%s\n" "\x1B[0m", line);
		return (1);
	}
	return (0);
}

int		main(void)
{
	int		fd;
	char	*line;

	fd = 0;
	while (get_next_line(fd, &line) > 0)
	{
		ft_color_player(line);
		ft_color_map(line);
		if (ft_color_res(line))
			;
		else if (*line == '*' || *line == '<' || *line == '.'
			|| *line == ' ' || *line == 'P')
			printf("%s\n", line);
		free(line);
		line = NULL;
	}
	return (0);
}
