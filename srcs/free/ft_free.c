/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 03:35:47 by amel-has          #+#    #+#             */
/*   Updated: 2023/12/30 13:57:55 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

static void	free_maps(t_maps *maps)
{
	int	i;

	i = 0;
	if (*(maps->con))
	{
		while (i < maps->len)
		{
			free(maps->con[i]);
			i++;
		}
	}
	free(maps->con);
}

void	ft_free(t_maps *maps)
{
	if (maps->con)
		free_maps(maps);
	free(maps);
}
