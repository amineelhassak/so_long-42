/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:24:21 by amel-has          #+#    #+#             */
/*   Updated: 2024/01/02 01:14:53 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.h"

void	print_cureent_move(t_maps *m)
{
	m->count_move = m->count_move + 1;
	ft_putnbr_fd(m->count_move, 1);
	write(1, "\n", 1);
}

static int	next_move(int *c, int x, int y, t_maps *m)
{
	if (m->con[c[0]][c[1]] == 'P' && m->con[c[0] + x][c[1] + y] != '1')
	{
		print_cureent_move(m);
		if (c[0] + x == m->enmy_x && c[1] + y == m->enmy_y)
		{
			ft_putendl_fd("BY !", 2);
			ft_exit(m);
		}
		if (m->con[c[0] + x][c[1] + y] != 'D')
		{
			if (!count(m))
				m->con[m->pos_ex][m->pos_ey] = 'D';
			(1 < 2) && (m->con[c[0]][c[1]] = '0',
					m->con[c[0] + x][c[1] + y] = 'P');
			(1 < 2) && (m->pl_x = c[0] + x, m->pl_y = c[1] + y, m->index = 1);
			if (m->con[m->pos_ex][m->pos_ey] == '0')
				m->con[c[0]][c[1]] = 'E';
			return (1);
		}
	}
	return (0);
}

void	ox_moves(t_maps *m, int x, int y)
{
	int	c[2];

	(1 == 1) && (c[0] = 0, c[1] = 0);
	while (m->con[c[0]] && count(m) >= 0)
	{
		c[1] = 0;
		while (m->con[c[0]][c[1]])
		{
			if ((m->con[c[0]][c[1]] == 'P' && m->con[c[0] + x][c[1] + y] == 'D'
				&& !count(m)) || (m->con[c[0]][c[1]] == 'P'
				&& m->con[c[0] + x][c[1] + y] == 'E' && !count(m)))
			{
				ft_putendl_fd("BRAVO", 1);
				ft_exit(m);
			}
			if (next_move(c, x, y, m) == 1)
				break ;
			c[1]++;
		}
		if (c[0]++ >= 0 && m->index)
			break ;
	}
}

static void	count_move(int x, int y, t_maps *map)
{
	ox_moves(map, x, y);
	map->index = 0;
}

int	move(int key, t_maps *map)
{
	if (map->count_enmy == 1)
		moves_enemy(map);
	else
		search_place_for_enmy(map);
	if (key == 13 || key == 126)
		count_move(-1, 0, map);
	else if (key == 0 || key == 123)
		count_move(0, -1, map);
	else if (key == 1 || key == 125)
		count_move(1, 0, map);
	else if (key == 2 || key == 124)
		count_move(0, 1, map);
	if (key == 53)
		ft_exit(map);
	return (1);
}
