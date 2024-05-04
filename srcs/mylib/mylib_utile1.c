/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylib_utile1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 06:21:14 by amel-has          #+#    #+#             */
/*   Updated: 2023/12/30 11:51:34 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

static void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

static void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	if (fd < 0)
		return ;
	if (s && fd)
	{
		ft_putstr_fd(s, fd);
		write(fd, "\n", 1);
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0 ;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (!s1[i] && !s2[i])
		return (0);
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*(s + count))
		count++;
	return (count);
}
