/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 21:28:19 by niabraha          #+#    #+#             */
/*   Updated: 2024/01/24 21:28:19 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	len_line(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (line[i] == '\n')
			return (i);
	return (-1);
}

static char	*ft_read_line(int fd, char *line)
{
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;

	bytes_read = 1;
	if (!line)
		return (NULL);
	while (len_line(line) == -1 && bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free (line);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer);
	}
	return (line);
}

char	*ft_return_line(char **line)
{
	char	*current_line;
	char	*next_line;
	int		len;

	len = len_line(*line);
	if (len == -1)
	{
		current_line = *line;
		*line = NULL;
		return (current_line);
	}
	current_line = ft_substr(*line, 0, len + 1);
	next_line = ft_substr(*line, len + 1, ft_strlen(*line) - len - 1);
	free(*line);
	*line = next_line;
	return (current_line);
}

char	*get_next_line(int fd)
{
	static char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0 || !line)
		return (NULL);
	line = ft_read_line(fd, line);
	if (!line)
		return (NULL);
	return (ft_return_line(&line));
}

int main()
{
	int fd = open("textou.txt", O_RDONLY);
	char *line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
