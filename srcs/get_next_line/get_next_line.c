/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 06:21:06 by amel-has          #+#    #+#             */
/*   Updated: 2023/12/30 11:51:53 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"
/*<<<<<<<<<<<<<< get_next_line >>>>>>>>>>>>>>>>>*/
char	*ft_getline(char *save)
{
	int		i;
	char	*str;

	i = 0;
	if (!*save)
		return ((char *)0);
	while (save[i] != '\n' && *(save + i))
		i++;
	if (save[i] == '\n')
		str = malloc((i + 2) * sizeof(char));
	else
		str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (*(save + i) != '\n' && *(save + i))
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

static char	*ft_save(char *save, int fd)
{
	char	*line;
	int		readhandl;

	if (!save)
		return (0);
	line = malloc(BUFFER_SIZE + 1);
	if (!line)
		return (0);
	readhandl = 1;
	while (!ft_strchr(save, '\n') && readhandl != 0)
	{
		readhandl = read(fd, line, BUFFER_SIZE);
		if (readhandl == -1)
		{
			free(line);
			return (0);
		}
		line[readhandl] = '\0';
		save = ft_strjoin(save, line);
	}
	free(line);
	return (save);
}

char	*ft_modifie_save(char *save)
{
	int		i;
	int		k;
	char	*str;

	i = 0;
	if (!save)
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i] || (save[i] == '\n' && save[i + 1] == '\0'))
	{
		free(save);
		return (NULL);
	}
	str = malloc((ft_strlen(save) - i + 2) * sizeof(char));
	if (!str)
		return (0);
	i++;
	k = 0;
	while (save[i])
		str[k++] = save[i++];
	str[k] = '\0';
	free(save);
	return (str);
}

char	*g_n_l(int fd)
{
	char			*line;
	static char		*save[OPEN_MAX];

	if (fd >= 0 && fd < OPEN_MAX && read(fd, 0, 0) == -1)
	{
		free(save[fd]);
		save[fd] = NULL;
		return (0);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!save[fd])
		save[fd] = ft_strdup("");
	save[fd] = ft_save(save[fd], fd);
	if (!save[fd])
	{
		free(save[fd]);
		return (0);
	}
	line = ft_getline(save[fd]);
	save[fd] = ft_modifie_save(save[fd]);
	return (line);
}
