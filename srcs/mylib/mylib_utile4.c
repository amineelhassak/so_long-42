/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylib_utile4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:05:32 by amel-has          #+#    #+#             */
/*   Updated: 2024/01/01 16:05:36 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"
/*<<<<<<<<<<<<<<<<<<< ft_itoa >>>>>>>>>>>>>>>>>>>>>*/
static void	ft_verf(int *n, long int *m)
{
	if (*m < 0)
	{
		*n = 1;
		*m = (*m) * (-1);
	}
}

static int	ft_size(long int n)
{
	long int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	return (count + 1);
}

char	*ft_itoa(int n)
{
	int			size;
	long int	m;
	char		*tab;

	m = n;
	n = 0;
	size = ft_size(m);
	tab = malloc(size + 1);
	if (!tab)
		return (0);
	tab[size] = '\0';
	size--;
	ft_verf(&n, &m);
	while (size >= 0)
	{
		tab[size] = m % 10 + 48;
		m = m / 10;
		size--;
	}
	if (n == 1)
		tab[0] = '-';
	return (tab);
}

static void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == (-2147483648))
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else if (n >= 0 && n < 10)
	{
		n = n + 48;
		ft_putchar_fd(n, fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
