/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:54:15 by niabraha          #+#    #+#             */
/*   Updated: 2024/01/16 14:24:00 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_return_line(char *stash)
{
	char	*line;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!stash[len])
		return (NULL);
	while (stash[len] && stash[len] != '\n')
		len++;
	line = malloc(sizeof(char) * (len + 2));
	if (!line)
		return (NULL);
	while (stash[i] && stash[len] != '\n')
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

char	*ft_remove_line(char *stash)
{
	char 	*remaining_line;
	int		len;
	int		i;

	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (!stash[len])
	{
		free(stash);
		return (NULL);
	}
	remaining_line = (char *) malloc (sizeof(char) * (ft_strlen(stash) - len + 1));
	if (!remaining_line)
		return (NULL);
	len++;
	i = 0;
	while (stash[len])
		remaining_line[i++] = stash[len++];
	remaining_line[i] = '\0';
	free(stash);
	return (remaining_line);	
}

char	*ft_read_line(int fd, char *stash)
{
	ssize_t	bytes_read;
	char	*buffer;

	bytes_read = 1;
	buffer = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
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
	stash = ft_read_line(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_return_line(stash);
	stash = ft_remove_line(stash);
	return (line);
}

/* int main()
{
	int fd = open("textou.txt", O_RDONLY);
	char *line = get_next_line(fd);
	printf("coucou main: %s\n", line);
	while (line != NULL)
	{
		printf("works<%s>", line);
		free(line);
		line = get_next_line(fd);
	}
	//printf("main plus loin: <%s>", line);
	close(fd);
} */
//1. Sauvegarder les lignes lues
//2. Sauvegarder chaque ligne
//3. Retourner chaque ligne
