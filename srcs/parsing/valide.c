/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 06:21:29 by amel-has          #+#    #+#             */
/*   Updated: 2024/01/02 02:57:19 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

bool	valide(t_maps *maps, t_var_rf *var, char *str)
{
	int			fd;
	t_vflood	v;

	(1 == 1) && (v.str = NULL, maps->count_c = 0, fd = 0);
	if (!check_name(str))
		return (ft_putendl_fd("error 1", 2), 0);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd("error 2", 2), 0);
	str = ft_strdup("");
	if (!str)
		return (ft_putendl_fd("error 3", 2), 0);
	var->s = g_n_l(fd);
	if (!var->s)
		return (free(str), 0);
	if (!read_file(str, var, maps, fd))
		return (ft_putendl_fd("error 4", 2), 0);
	(1 == 1) && (maps->len = 0, v.i = 0);
	if (!valide_flood_fill(maps, v))
		return (ft_putendl_fd("error 5", 2), 0);
	return (1);
}
