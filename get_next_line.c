/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:54:15 by niabraha          #+#    #+#             */
/*   Updated: 2024/01/09 18:40:52 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clean(char *str)
{
	free(str);
	str = NULL;
	return (NULL);
}

char	*ft_return_line(char *stash)
{
	char	*line;
	int		len;

	len = 0;
	if (!stash[len])
		return (ft_clean(stash));
	while (stash[len] != '\n' && stash[len] != '\0')
		len++;
	line = malloc(sizeof(char) * (len + 2));
	if (!line)
		return (NULL);
	len = 0;
	while (stash[len] != '\n' && stash[len] != '\0')
	{
		line[len] = stash[len];
		len++;
	}
	if (stash[len] == '\n')
	{
		line[len] = stash[len];
		len++;
	}
	line[len] = '\0';
	return (line);
}

char	*ft_save_line(char *stash)
{
	char	*line;
	int		next_line;
	int		current_line;

	next_line = 0;
	current_line = 0;
	while (stash[next_line] != '\n' && stash[next_line] != '\0')
		next_line++;
	if (!stash[next_line])
		return (ft_clean(stash));
	line = (char *) malloc(sizeof(char) * ((ft_strlen(stash) - next_line) + 1));
	if (!line)
		return (NULL);
	next_line++;
	while (stash[next_line] != '\n' && stash[next_line] != '\0')
	{
		line[current_line] = stash[next_line];
		current_line++;
	}
	line[current_line] = '\0';
	free(stash);
	return (line);
}

char	*ft_save_all(int fd, char *stash)
{
	int		read_bytes;
	char	*buffer;

	buffer = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(stash, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	stash = ft_save_all(fd, stash);
	if (!stash)
	{
		free(stash);
		return (NULL);
	}
	line = ft_save_line(stash);
	stash = ft_return_line(stash);
	return (line);
}

//1. Sauvegarder les lignes lues
//2. Sauvegarder chaque ligne
//3. Retourner chaque ligne