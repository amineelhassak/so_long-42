/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_mat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 03:35:37 by amel-has          #+#    #+#             */
/*   Updated: 2024/01/02 02:49:26 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

char	**allocatematrix(int *rows, int *cols)
{
	char	**mat;
	int		i;

	i = -1;
	mat = malloc((*rows + 1) * sizeof(char **));
	if (!mat)
		return (0);
	while (++i < *rows)
	{
		mat[i] = malloc((*cols + 1) * sizeof(char *));
		if (!mat[i])
			return (0);
	}
	return (mat);
}
