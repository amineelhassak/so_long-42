/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 03:35:44 by amel-has          #+#    #+#             */
/*   Updated: 2023/12/30 14:00:30 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

t_maps	*c_list(void)
{
	t_maps	*new_maps;

	new_maps = malloc(sizeof(t_maps));
	if (!new_maps)
		return (0);
	new_maps->con = NULL;
	return (new_maps);
}
