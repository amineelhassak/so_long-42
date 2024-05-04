/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylibft_utile3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 06:21:19 by amel-has          #+#    #+#             */
/*   Updated: 2023/12/30 11:50:16 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s2)
		return (0);
	return (ft_strcpy(s2, (char *)s1));
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char )c)
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return ((s + i));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	int		n;
	int		m;
	int		i;
	int		j;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	n = ft_strlen(s1);
	m = ft_strlen(s2);
	i = -1;
	tab = (char *)malloc(m + n + 1);
	if (!tab)
		return (free((char *)s1), NULL);
	while (*(s1 + (++i)))
		tab[i] = s1[i];
	j = -1;
	while ((++j) < m)
		tab[i + j] = s2[j];
	tab[i + j] = '\0';
	return (free((char *)s1), tab);
}
