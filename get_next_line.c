/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:54:15 by niabraha          #+#    #+#             */
/*   Updated: 2024/01/10 16:17:08 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <assert.h>
#include <stdio.h>

char	*ft_remaining(char *stash)
{
	char	*line;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!stash)
		return (NULL);
	while (stash[len] && stash[len] != '\n')
		len++;
	line = malloc(sizeof(char) * (len + 2));
	if (!line)
		return (NULL);
	while (stash && stash[len] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}


char	*ft_return_line(char *stash)
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
char	*ft_save_all(int fd, char *stash)
{
	int		read_bytes;
	char	*buffer;

	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (buffer && !stash)
		{
			stash = ft_substr(buffer, 0, read_bytes);
			if (!stash)
				return (free(buffer), NULL);
		}
		if (read_bytes == -1)
		{
			free(buffer);
			if (stash)
				return (free(stash), NULL);
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
		return (0);
	stash = ft_save_all(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_return_line(stash); // basile boli
	printf("ca c basile :%s\n", line);
	stash = ft_remaining(stash); // tete de zidane barthez le gardien
	printf("ca c zidane et barthez%s\n", line);
	return (line);
}

int main()
{
	int fd = open("textou.txt", O_RDONLY);
	char *line = get_next_line(fd);
	printf("coucou main: %s\n", line);
	while (line != NULL)
	{
		printf("bite<%s>", line);
		free(line);
		line = get_next_line(fd);
	}
	printf("main chatte: <%s>", line);
	close(fd);
}
//1. Sauvegarder les lignes lues
//2. Sauvegarder chaque ligne
//3. Retourner chaque ligne
