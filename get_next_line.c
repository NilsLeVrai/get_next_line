/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 21:28:19 by niabraha          #+#    #+#             */
/*   Updated: 2024/01/29 15:33:39 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_len_and_end(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (FALSE);
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (i + 1);
		i++;
	}
	return (FALSE);
}

static char	*ft_read_line(int fd, char *line)
{
	char		buffer[BUFFER_SIZE + 1];
	int			bytes_read;
	char		*tmp;

	bytes_read = 1;
	while (check_len_and_end(line) != TRUE && bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(line), line = NULL, NULL);
		buffer[bytes_read] = '\0';
		if (!line)
		{
			line = ft_strdup(buffer);
			if (!line)
				return (NULL);
		}
		else
		{ 
			tmp = ft_strjoin(line, buffer);
			free(line);
			line = tmp;
			if (!line)
				return (NULL);
		}
		if (!line)
			return (free(line), line = NULL, NULL);
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
	len--;
	current_line = ft_substr(*line, 0, len + 1);
	next_line = ft_substr(*line, len + 1, ft_strlen(*line) - len - 1);
	free(*line);
	*line = next_line;
	if (!current_line || !next_line || !ft_strlen(current_line))
	{
		free (current_line);
		return (free (*line), *line = NULL, NULL);
	}
	return (current_line);
}

char	*get_next_line(int fd)
{
	static char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_read_line(fd, line);
	if (!line)
		return (free (line), line = NULL, NULL);
	if (ft_strlen(line) < 1)
		return (free (line), line = NULL, NULL);
	return (ft_return_line(&line));
}

/* 	int main()
{
	int fd = open("42_with_nl.txt", O_RDONLY);
	char *line = get_next_line(fd);
 	while (line != NULL)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
	}  
	printf("%s", line);
	free (line);
	close(fd);
} */
