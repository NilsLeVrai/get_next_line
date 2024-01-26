/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 21:28:19 by niabraha          #+#    #+#             */
/*   Updated: 2024/01/25 15:20:50 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_len_and_end(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (FALSE);
}

static char	*ft_read_line(int fd, char *line)
{
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;

	bytes_read = 1;
	if (!line)
		return (NULL);
	while (check_len_and_end(line) != TRUE && bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free (line);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
		{
			free (line);
			line = NULL;
			return (NULL);
		}
	}
	return (line);
}

char	*ft_return_line(char **line)
{
	char	*current_line;
	char	*next_line;
	int		len;

	len = check_len_and_end(*line);
	if (len == FALSE)
	{
		current_line = *line;
		*line = NULL;
		return (current_line);
	}
	current_line = ft_substr(*line, 0, len + 1);
	next_line = ft_substr(*line, len + 1, ft_strlen(*line) - len - 1);
	free(*line);
	*line = next_line;
	if (!current_line || !next_line || !ft_strlen(next_line))
	{
		free (next_line);
		free (*line);
		*line = NULL;
		return (NULL);
	}
	printf("yo le rap%p\n", current_line);
	return (current_line);
}

char	*get_next_line(int fd)
{
	static char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	if (!line)
	{
		line = (char *) malloc(sizeof(char) * 1); // ???? buggy bugger
		if (!line)
			return (free (line), line = NULL, NULL);
		line[0] = '\0';
	}
	line = ft_read_line(fd, line);
	if (!line)
		return (free (line), line = NULL, NULL);
	if (ft_strlen(line) == 0)
		return (free (line), line = NULL, NULL);
	
	return (ft_return_line(&line));
}

int main()
{
	int fd = open("te.txt", O_RDONLY);
	char *line = get_next_line(fd);
/* 	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	} */
	printf("%s", line);
	printf("yo le sk8er boi%p\n", line);
	free (line);
	close(fd);
}
