/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:54:15 by niabraha          #+#    #+#             */
/*   Updated: 2024/01/10 16:35:07 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <assert.h>
#include <stdio.h>

char	*ft_return_line(int fd, char **stash)
{
	int		len;
	char	*current_line;
	char	*remaining;

	len = 0;
	if (!stash)
		return (NULL);
	while (*stash && stash[fd][len] != '\n')
		len++;
	len++;
	current_line = ft_substr(stash[fd], 0, len);
	remaining = ft_substr(stash[fd], len, ft_strlen(&stash[fd][len]));
	free(stash[fd]);
	stash[fd] = remaining;
	return (current_line);
}
char	*ft_parsing(int fd, char **stash, char *tmp)
{
	int		read_bytes;
	char	*buffer;

	read_bytes = 1;
	while (read_bytes != 0)
	{
		read_bytes = read(fd, tmp, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(stash[fd]);
			return (NULL);
		}
		else
		{
			buffer = ft_strjoin(stash[fd], tmp);
			free(stash[fd]);
			stash[fd] = buffer;
		}
		if (stash[fd] && (ft_strchr(stash[fd], '\n')) || read_bytes == 0)
			return (stash[fd]);
	}
	return (NULL);
}


char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[4096];
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (0);
	tmp = (char *) malloc((sizeof(char) * (BUFFER_SIZE + 1)));
	if (!tmp)
		return (NULL);
	stash[fd] = ft_parsing(fd, stash, tmp);
	if (!stash)
		return (NULL);
	line = ft_return_line(fd, stash); // basile boli
	return (line);
}


//1. Sauvegarder les lignes lues
//2. Sauvegarder chaque ligne
//3. Retourner chaque ligne
