/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:54:15 by niabraha          #+#    #+#             */
/*   Updated: 2024/01/15 14:30:06 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


char *ft_saving_to_stash(int fd, char *stash, ssize_t bytes_read)
{
	char 	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes_read] = '\0';	
	return (buffer);
}

char *get_next_line(int fd)
{
	char 	*stash; //tout le texte
	char 	*line; // une ligne
	ssize_t bytes_read;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	bytes_read = 1;
	stash = ft_saving_to_stash(fd, stash, bytes_read); // sauvegarde tout mon texte
	/* line = ft_return_line(stash); //return la ligne
	stash = ft_remaining(stash); // sauvegarde le reste */
	return (stash);
}

int main()
{
	int fd = open("textou.txt", O_RDONLY);
	char *line = get_next_line(fd);
	while (line != NULL)
	{
		printf("oui : <%s>\n", line);
		free(line);
		line = get_next_line(fd);
	}
	printf("non : <%s>\n", line);
	close(fd);
}
//1. Sauvegarder les lignes lues
//2. Sauvegarder chaque ligne
//3. Retourner chaque ligne
