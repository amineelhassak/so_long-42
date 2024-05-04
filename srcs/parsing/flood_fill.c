/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 03:35:13 by amel-has          #+#    #+#             */
/*   Updated: 2024/01/02 02:56:38 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

static bool	ox_valide_flood_fill(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'C' || str[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	flood_fill(char **str, int i, int j, t_maps *s_maps)
{
	if (i < 0 || j < 0 || i >= s_maps->len)
		return ;
	if (j >= s_maps->width || str[i][j] == 'F' || str[i][j] == '1')
		return ;
	str[i][j] = 'F';
	flood_fill(str, i + 1, j, s_maps);
	flood_fill(str, i - 1, j, s_maps);
	flood_fill(str, i, j + 1, s_maps);
	flood_fill(str, i, j - 1, s_maps);
}

void	free_mat(char **str, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		free(str[i]);
	free(str);
}

bool	valide_flood_fill(t_maps *maps, t_vflood v)
{
	while (maps->con[maps->len])
		maps->len++;
	v.str = allocatematrix(&maps->len, &maps->width);
	if (!v.str)
		return (false);
	while (maps->con[v.i])
	{
		v.j = 0;
		while (maps->con[v.i][v.j])
		{
			if (maps->con[v.i][v.j] == 'P')
				(1 == 1) && (maps->pl_x = v.i, maps->pl_y = v.j);
			if (maps->con[v.i][v.j] == 'E')
				(1 == 1) && (maps->pos_ex = v.i, maps->pos_ey = v.j);
			if (maps->con[v.i][v.j] == 'C')
				maps->count_c++;
			(1 < 2) && (v.str[v.i][v.j] = maps->con[v.i][v.j], v.j++);
		}
		(1 == 1) && (v.str[v.i][v.j] = '\0', v.i++);
	}
	v.str[v.i] = 0;
	flood_fill (v.str, maps->pl_x, maps->pl_y, maps);
	if (!ox_valide_flood_fill(v.str))
		return (free_mat(v.str, maps->len), false);
	return (free_mat(v.str, maps->len), true);
}
