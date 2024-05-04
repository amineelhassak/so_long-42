/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 04:14:52 by amel-has          #+#    #+#             */
/*   Updated: 2023/12/30 13:57:13 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

int	cal_len(char *str)
{
	int	c;

	c = 0;
	while (str[c] && str[c] != '\n')
		c++;
	return (c);
}

bool	ox_read_file(t_var_rf *var, t_maps *maps, char *str)
{
	int	count_world;

	count_world = 0;
	maps->width = var->n;
	maps->len++;
	str = ft_strjoin(str, var->s);
	if (!(str))
		return (free(str), 0);
	maps->con = ft_split(str, '\n', &count_world);
	if (!(maps->con))
		return (free(str), 0);
	return (free(str), 1);
}

static void	read_free(char *s1, char *s2, char *s3)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	if (s3)
		free(s3);
}

int	valide_read(t_var_rf *S, int fd)
{
	S->str = g_n_l(fd);
	if (!S->str)
		return (0);
	if (!S->s)
		return (0);
	return (1);
}

bool	read_file(char *str, t_var_rf *S, t_maps *maps, int fd)
{
	maps->count_move = 0;
	if (!isone(S->s))
		return (read_free(str, S->s, 0), 0);
	while (valide_read(S, fd))
	{
		str = ft_strjoin(str, S->s);
		if (!str)
			return (read_free(str, S->str, S->s), 0);
		(1 == 1) && (maps->len++, S->n = cal_len(S->s));
		if (!is_valide(S))
			return (read_free(str, S->str, 0), 0);
		(1 == 1) && (free(S->s), S->s = S->str);
		if (S->s)
		{
			if (S->n != cal_len(S->s))
				return (read_free(str, S->s, 0), 0);
		}
	}
	if (!isone(S->s) || S->s[S->n] == '\n'
		|| S->c_e != 1 || S->c_p != 1 || S->c_coll == 0)
		return (free(S->s), free(str), 0);
	if (!ox_read_file(S, maps, str))
		return (free(S->s), 0);
	return (free(S->s), 1);
}
