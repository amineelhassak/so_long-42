/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 20:04:47 by amel-has          #+#    #+#             */
/*   Updated: 2024/01/02 02:33:54 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.h"

void	hook_mlx(t_maps *map)
{
	mlx_hook(map->mlx_win, 2, 0, move, map);
	mlx_hook(map->mlx_win, 17, 0, ft_exit, map);
}

void	search_place_for_enmy(t_maps *map)
{
	int			i;
	int			j;
	static int	count_enmy;

	(1 == 1) && (i = 0, map->i = 0, map->count_enmy = 0);
	while (map->con[i] && !map->i && !count_enmy)
	{
		j = 0;
		while (map->con[i][j])
		{
			if ((map->con[i][j] == '0' && map->con[i + 1][j] ==
				'0' && map->con[i + 2][j] == '0' && map->count_enmy == 0))
			{
				count_enmy++;
				map->count_enmy++;
				map->enmy_x = i;
				map->enmy_y = j;
				break ;
			}
			j++;
		}
		if (map->count_enmy)
			break ;
		i++;
	}
}

void	moves_enemy(t_maps *map)
{
	static int	turn;
	static int	jay;

	if (map->con[map->enmy_x][map->enmy_y] == 'P')
	{
		ft_putendl_fd("BY !!!", 2);
		ft_exit(map);
	}
	if ((!jay && turn < map->len && map->con[map->enmy_x + 1][map->enmy_y]
		== '0'))
	{
		map->con[map->enmy_x][map->enmy_y] = '0';
		map->enmy_x++;
		turn++;
	}
	if (map->con[map->enmy_x + 1][map->enmy_y] != '0')
		jay = 1;
	if ((jay && turn > 0 && map->con[map->enmy_x - 1][map->enmy_y] == '0'))
	{
		map->con[map->enmy_x][map->enmy_y] = '0';
		map->enmy_x--;
		turn--;
	}
	if (jay && map->con[map->enmy_x - 1][map->enmy_y] != '0')
		jay = 0;
}
