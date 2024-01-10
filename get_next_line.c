/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:54:15 by niabraha          #+#    #+#             */
/*   Updated: 2024/01/10 10:18:39 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	size_s1;
	size_t	size_s2;
	char	*p;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	p = (char *) malloc (sizeof(char) * (size_s1 + size_s2 + 1));
	if (!p)
		return (NULL);
	while (*s1)
		p[i++] = *s1++;
	while (*s2)
		p[i++] = *s2++;
	p[i] = '\0';
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int		i;
	unsigned char		char_find;
	size_t				len;

	char_find = (unsigned char) c;
	i = 0;
	len = (size_t) ft_strlen(s);
	while (i <= (unsigned int) len)
	{
		if (s[i] == char_find)
			return ((char *) &s[i]);
		i++;
	}
	return (NULL);
} */

char	*ft_return_line(char *stash)
{
	char	*line;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!stash[len])
		return (NULL);
	while (stash[len] != '\n' && stash[len])
		len++;
	line = malloc(sizeof(char) * (len + 2));
	if (!line)
		return (NULL);
	while (stash[i] != '\n' && stash[i])
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


char	*ft_save_line(char *stash)
{
	char	*line;
	int		next_line;
	int		current_line;

	next_line = 0;
	current_line = 0;
	while (stash[next_line] != '\n' && stash[next_line])
		next_line++;
	if (!stash[next_line])
		return (NULL);
	line = malloc(sizeof(char) * (ft_strlen(stash) - next_line + 1));
	if (!line)
		return (NULL);
	next_line++;
	while (stash[next_line])
	{
		line[current_line] = stash[next_line];
		current_line++;
		next_line++;
	}
	line[current_line] = '\0';
	free(stash);
	return (line);
}

char	*ft_save_all(int fd, char *stash)
{
	int		read_bytes;
	char	*buffer;

	buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(stash, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			if (stash)
				free (stash);
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
	static char	*stash[4096];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (0);
	stash[fd] = ft_save_all(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_save_line(stash[fd]);
	stash[fd] = ft_return_line(stash[fd]);
	return (line);
}
#include <stdio.h>
#include <fcntl.h>
#include <assert.h>

int main()
{
	int fd = open("textou.txt", O_RDONLY);
	char *line = get_next_line(fd);
	while (line != NULL)
	{
		printf("<%s>", line);
		free(line);
	line = get_next_line(fd);
	}
	printf("<%s>", line);
	close(fd);
}
//1. Sauvegarder les lignes lues
//2. Sauvegarder chaque ligne
//3. Retourner chaque ligne
