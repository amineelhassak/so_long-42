/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_to_imags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:00:08 by amel-has          #+#    #+#             */
/*   Updated: 2024/01/01 20:09:04 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.h"

static int	point_to_img(t_maps *map, char *filename, int i)
{
	int	x;
	int	y;

	map->img[i] = mlx_xpm_file_to_image(map->mlx, filename, &x, &y);
	if (!map->img[i] || x > 50 || y > 50)
		return (0);
	return (1);
}

int	_imags_(t_maps *map)
{
	int		i;
	char	*path[10];

	i = -1;
	path[0] = "imgs/p_r.xpm";
	path[1] = "imgs/c.xpm";
	path[2] = "imgs/close_door.xpm";
	path[3] = "imgs/floor.xpm";
	path[4] = "imgs/wall1.xpm";
	path[5] = "imgs/open_door.xpm";
	path[6] = "imgs/enemyf1.xpm";
	path[7] = "imgs/enemyf2.xpm";
	path[8] = "imgs/enemyf3.xpm";
	path[9] = "imgs/enemyf4.xpm";
	while (++i < 10)
	{
		if (!point_to_img(map, path[i], i))
			return (0);
	}
	return (1);
}
