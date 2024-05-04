/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 03:35:23 by amel-has          #+#    #+#             */
/*   Updated: 2023/12/30 11:47:04 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

bool	check_name(char *str)
{
	str = ft_strchr(str, '.');
	if (!str)
		return (false);
	if (ft_strncmp(str, ".ber", 4))
		return (false);
	return (true);
}

bool	is_valide(t_var_rf *var)
{
	int	n;
	int	i;

	i = 0;
	n = cal_len(var->s);
	if (var->s[0] != '1' || var->s[n - 1] != '1')
		return (free(var->s), ft_putendl_fd("Error 7", 2), 0);
	while ((var->s)[i] && (var->s)[i] != '\n')
	{
		if ((var->s)[i] != 'E' && (var->s)[i] != 'C' && (var->s)[i] != 'P'
		&& (var->s)[i] != '1' && (var->s)[i] != '0')
			return (free(var->s), ft_putendl_fd("Error 8", 2), false);
		if ((var->s)[i] == 'E')
			(var->c_e)++;
		else if ((var->s)[i] == 'C')
			(var->c_coll)++;
		else if ((var->s)[i] == 'P')
			(var->c_p)++;
		else if ((var->s)[i] == '1')
			(var->c_o)++;
		i++;
	}
	return (true);
}

bool	isone(char *str)
{
	while (*str && *str != '\n')
	{
		if (*str != '1')
			return (false);
		str++;
	}
	return (true);
}
