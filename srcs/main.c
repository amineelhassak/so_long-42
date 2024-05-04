/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 06:21:32 by amel-has          #+#    #+#             */
/*   Updated: 2024/01/02 03:54:46 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.h"

int	main(int c, char **v)
{
	t_var_rf		var;
	t_maps			*map;

	map = NULL;
	initialization(map, &var);
	if (c == 2)
	{
		map = c_list();
		if (!map)
			return (ft_free(map), 1);
		map->index_enmy = 0;
		if (!valide(map, &var, v[1]))
			return (ft_putendl_fd("Error\n", 1), ft_free(map), 1);
		map->enmy_x = 0;
		map->enmy_y = 0;
		mlx(map);
	}
	else
		return (ft_putendl_fd("Error\n", 2), 1);
	return (ft_free(map), 0);
}
