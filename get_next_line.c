/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 21:28:19 by niabraha          #+#    #+#             */
/*   Updated: 2024/01/26 18:43:11 by niabraha         ###   ########.fr       */
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
	char *tmp;

	bytes_read = 1;
	while (check_len_and_end(line) != TRUE && bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free (line);
			fflush(NULL);
			line = NULL;
			return (NULL);
		}	
		buffer[bytes_read] = '\0';
		if (!line)
		{
			line = ft_strdup(buffer);
			if (!line)
			{
				return (NULL);
			}
				
		}
		else 
		{
			tmp = ft_strjoin(line, buffer);
			free(line);
			line = tmp;
		
			if (!line)
			{	
				return (NULL);
			}
				
		}
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
		//printf("lol");
		return (current_line);
	} 
	len--;

	current_line = ft_substr(*line, 0, len + 1);
	
	next_line = ft_substr(*line, len + 1, ft_strlen(*line) - len - 1);

	free(*line);
	*line = next_line;
	//printf("ceci est l'incroyable current_line111111: %s\n", current_line);
	//fflush(NULL);
	if (!current_line || !next_line || !ft_strlen(current_line))
	{
		//printf("ceci est l'incroyable current_line222222: %s\n", current_line);
		//fflush(NULL);
		free (current_line);
		free (*line);
		*line = NULL;
		return (NULL);
	}	
	//printf("ceci est l'incroyable current_line3333333: %s\n", current_line);
	//fflush(NULL);
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
	int fd = open("alexis.txt", O_RDONLY);
	char *line = get_next_line(fd);
 	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}  
	printf("%s", line);
	free (line);
	close(fd);
	line = get_next_line(1000);
	printf("%s", line);
	free (line);
	fd = open("alexis.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free (line);
	close(fd);
	line = get_next_line(1000);
	printf("%s", line);
	free (line);
	fd = open("alexis.txt", O_RDONLY); 
} */