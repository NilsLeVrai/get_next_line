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

char	*ft_return_line(int fd, char *stash)
{
	char	*lines;
	int		next_line;
	int		current_line;

	next_line = 0;
	current_line = 0;
	while (stash && stash[current_line] != '\n')
		current_line++;
	if (!stash)
		return (NULL);
	lines = malloc(sizeof(char) * (ft_strlen(stash) - current_line + 1));
	if (!lines)
		return (NULL);
	current_line++;
	while (stash[current_line])
	{
		lines[next_line] = stash[current_line];
		current_line++;
		next_line++;
	}
	lines[next_line] = '\0';
	free(stash);
	return (lines);
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
