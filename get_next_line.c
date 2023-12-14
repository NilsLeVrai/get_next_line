/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:54:15 by niabraha          #+#    #+#             */
/*   Updated: 2023/12/14 12:23:57 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
read file: (while bytes_read > 0)
write line: ()
delete line:
function deleting and joining lines
*/

static void	*free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (NULL);
}

char	*next_line(int fd)
{

}

char*	write_line(int fd)
{
}
char	*parsing_file(int fd, char *line)
{
	char *p;

	p =
	while (buffer > 0)
	{

	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char*	stash;
	char*			buffer;
	char*			line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(stash);
		stash = NULL;
		return (stash);
	}
	buffer = parsing_file(fd, line);
	if (!buffer)
		return (NULL);
	line = write_line(buffer);
	buffer = next_line(buffer);
	return (line);
}
