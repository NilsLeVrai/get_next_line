/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:54:15 by niabraha          #+#    #+#             */
/*   Updated: 2023/12/18 14:17:01 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
read file: (while bytes_read > 0)
write line: ()
delete line:
function deleting and joining lines
*/

/* static void	*free_tab(char **tab)
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

	if (!p = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)));
		return (NULL);
	while (buffer > 0)
	{

	}
	return (line);
} */

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		*stash;

	stash = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!stash)	
		return (NULL);
	bytes_read = read(fd, stash, BUFFER_SIZE);
	if (bytes_read < 0 || BUFFER_SIZE < 0)
		return (NULL);
	while (bytes_read >= 0)
	{
		stash[bytes_read] = '\0';
		if (ft_strchr(stash, '\n'))
			return (parsing_file(fd, stash));
	}
	if (bytes_read == 0)
		return (NULL);
	return (stash);
}
