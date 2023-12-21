/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:54:15 by niabraha          #+#    #+#             */
/*   Updated: 2023/12/21 15:37:25 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clean(char *str)
{
	char	*p;

	p = NULL;
	if (str)
	{
		p = ft_strdup(str);
		free(str);
	}
	return (p);
}

char	*ft_clean_stash(char *str)
{
}

char	*get_line(char*str)
{
	char	*del; // del is the address of the first \n in str
	char*	line; // line is the line to be returned
	int		len; // len is the length of the line to be returned

	del = ft_strchr(str, "\n");
	len = (del - str) + 1;
	line = ft_substr(str, 0, len);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[4096];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	line = get_line(stash[fd]);
	if (!line)
		return (&ft_clean(stash[fd]));
	stash[fd] = ft_clean_stash(stash[fd]);
	return (line);
}
