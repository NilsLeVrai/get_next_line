/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:54:15 by niabraha          #+#    #+#             */
/*   Updated: 2024/01/09 15:44:33 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//read, malloc, free

char	*ft_clean(char *str)
{
	free(str);
	str = NULL;
	return (NULL);
}

/* char	*ft_return_line(char *line)
{
	
}
*/

char	*ft_save_line(char *stash)
{
	char	*line;
	int		size_line;

	size_line = 0;
	while (stash[size_line] != '\n' && stash[size_line] != '\0')
		size_line++;
	if (!stash[size_line])
		return (ft_clean(stash));
	line = (char *) malloc(sizeof(char) * (size_line + 2)); //+2 pour \n et \0
	if (!line)
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		line[i] = stash[i];
		i++;
	}
	{
		line[i] = stash[i];
		i++;
	}
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
			return (ft_clean(buffer));
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
		return (ft_clean(stash));
	//line = "oui";
	line = ft_save_line(stash);
	//stash = ft_return_line(stash);
	return (line);
}

//1. Sauvegarder les lignes lues
//2. Sauvegarder chaque ligne
//3. Retourner chaque ligne
