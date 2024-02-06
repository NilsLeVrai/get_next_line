/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:47:17 by niabraha          #+#    #+#             */
/*   Updated: 2024/02/06 12:28:28 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	char		*tmp;
	ssize_t		bytes_read;

	bytes_read = 1;
	while (check_len_and_end(line) != TRUE && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free (line), line = NULL, NULL);
		buffer[bytes_read] = '\0';
		if (line == NULL)
			tmp = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(line, buffer);
			free(line);
		}
		if (!tmp)
			return (NULL);
		line = tmp;
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
	static char	*line[1048576];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1048576)
		return (NULL);
	line[fd] = ft_read_line(fd, line[fd]);
	if (!line[fd])
		return (free (line[fd]), line[fd] = NULL, NULL);
	if (ft_strlen(line[fd]) < 1)
		return (free (line[fd]), line[fd] = NULL, NULL);
	return (ft_return_line(&line[fd]));
}
