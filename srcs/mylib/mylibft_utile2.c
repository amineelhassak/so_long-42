/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylibft_utile2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 01:06:17 by amel-has          #+#    #+#             */
/*   Updated: 2023/12/30 11:51:20 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"
/*<<<<<<<<<<<<<<<<<<< split >>>>>>>>>>>>>>>>>>>>>*/
static int	count_words(char const *str, char c)
{
	int	index;
	int	count;
	int	i;

	count = 0;
	index = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			index = 0;
		else if (index == 0)
		{
			count++;
			index = 1;
		}
		i++;
	}
	return (count);
}

void	*f_free_split(char **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(arr[i++]);
	free(arr);
	return (0);
}

static char	*get_word(const char *s, char c)
{
	char	*word;
	size_t	len;
	size_t	i;

	i = -1;
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc(len + 1);
	if (!word)
		return (0);
	while ((++i) < len)
		word[i] = s[i];
	word[len] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c, int *count_world)
{
	char	**str;
	int		i;

	i = 0;
	if (!s)
		return (0);
	*count_world = count_words(s, c);
	str = malloc(((*count_world) + 1) * sizeof(char *));
	if (!str)
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			str[i] = get_word(s, c);
			if (!str[i])
				return (f_free_split(str, i));
			while (*s && *s != c)
				s++;
			i++;
		}
	}
	return (str[i] = NULL, str);
}
