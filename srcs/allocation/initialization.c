/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:06:49 by amel-has          #+#    #+#             */
/*   Updated: 2024/01/01 20:47:55 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

void	initialization(t_maps *map, t_var_rf *var)
{
	var->c_e = 0;
	var->c_coll = 0;
	var->c_o = 0;
	var->c_p = 0;
	(void)map;
}
