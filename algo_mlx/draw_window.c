/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:45:05 by amel-has          #+#    #+#             */
/*   Updated: 2024/01/02 01:06:08 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.h"

int	count(t_maps *map)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (map->con[i])
	{
		j = 0;
		while (map->con[i][j])
		{
			if (map->con[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

static void	oxe_draw_window(t_maps *map, int i, int j, int x)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->img[3], j * 50, i * 50);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img[x],
		j * 50, i * 50);
}

static int	ox_draw_window(t_maps *map, int i, int j)
{
	if (map->con[i][j] == 'P')
		return (oxe_draw_window(map, i, j, 0), 1);
	else if (map->con[i][j] == 'C')
		return (oxe_draw_window(map, i, j, 1), 1);
	else if (map->con[i][j] == 'E')
		return (oxe_draw_window(map, i, j, 2), 1);
	else if (map->con[i][j] == 'M')
		return (oxe_draw_window(map, i, j, 6), 1);
	else if (map->con[i][j] == '1')
	{
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->img[4], j * 50, i * 50);
		return (1);
	}
	else if (map->con[i][j] == '0')
	{
		mlx_put_image_to_window(map->mlx,
			map->mlx_win, map->img[3], j * 50, i * 50);
		return (1);
	}
	return (0);
}

void	fun(t_maps *map)
{
	char	*str;

	str = ft_itoa(map->count_move);
	if (!str)
		ft_exit(map);
	mlx_string_put(map->mlx, map->mlx_win, 5, 5, 0xf9b405, str);
	free(str);
}

void	draw_window(t_maps *map)
{
	t_vflood	v;
	int			x;

	(1 == 1) && (v.i = 0, x = 0);
	while (map->con[v.i])
	{
		v.j = 0;
		while (map->con[v.i][v.j])
		{
			ox_draw_window(map, v.i, v.j);
			if (map->con[v.i][v.j] == 'D' && x == 0)
				oxe_draw_window(map, v.i, v.j, 5);
			else if (map->con[v.i][v.j] == 'N' && x == 0)
				oxe_draw_window(map, v.i, v.j, 7);
			else if (map->con[v.i][v.j] == 'Y' && x == 0)
				oxe_draw_window(map, v.i, v.j, 8);
			else if (map->con[v.i][v.j] == 'L' && x == 0)
				oxe_draw_window(map, v.i, v.j, 9);
			v.j++;
		}
		v.i++;
	}
	fun(map);
}
