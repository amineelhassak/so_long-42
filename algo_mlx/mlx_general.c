/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_general.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:23:13 by amel-has          #+#    #+#             */
/*   Updated: 2024/01/02 02:34:09 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.h"

static void	ox_affiche_enmy(t_maps *map)
{
	mlx_clear_window(map->mlx, map->mlx_win);
	draw_window(map);
}

int	affiche_enmy(t_maps *map)
{
	if (map->count_enmy == 1)
	{
		if (map->index_enmy == 0)
		{
			map->con[map->enmy_x][map->enmy_y] = 'K';
			map->index_enmy = 1;
		}
		else if (map->index_enmy == 1)
		{
			map->index_enmy = 4;
			map->con[map->enmy_x][map->enmy_y] = 'N';
		}
		else if (map->index_enmy == 3)
		{
			map->index_enmy = 0;
			map->con[map->enmy_x][map->enmy_y] = 'Y';
		}
		else if (map->index_enmy == 4)
		{
			map->index_enmy = 3;
			map->con[map->enmy_x][map->enmy_y] = 'L';
		}
	}
	return (ox_affiche_enmy(map), 1);
}

void	mlx(t_maps *m)
{
	m->mlx = mlx_init();
	if (!m->mlx)
		ft_exit(m);
	m->mlx_win = mlx_new_window(m->mlx, m->width * 50, m->len * 50, "so_long");
	if (!m->mlx)
		ft_exit(m);
	if (!_imags_(m))
		ft_exit(m);
	draw_window(m);
	m->enmy_x = 0;
	m->enmy_y = 0;
	search_place_for_enmy(m);
	hook_mlx(m);
	mlx_loop_hook(m->mlx, affiche_enmy, m);
	mlx_loop(m->mlx);
}
