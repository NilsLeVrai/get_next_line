/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:13:32 by niabraha          #+#    #+#             */
/*   Updated: 2023/12/18 14:24:42 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
char	*ft_strchr(const char *s, int c)
{
	unsigned int		i;
	unsigned char		char_find;
	size_t				len;

	char_find = (unsigned char) c;
	i = 0;
	len = (size_t) ft_strlen(s);
	while (i <= (unsigned int) len)
	{
		if (s[i] == char_find)
			return ((char *) &s[i]);
		i++;
	}
	return (NULL);
}


char	*get_next_line(int fd)
{
	int			bytes_read;
	char		*stash;

	stash = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!stash)	
		return (NULL);
	bytes_read = read(fd, stash, BUFFER_SIZE);
	printf()
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	return (stash);
}

int main()
{
	int		fd;
	char	*line;
	int		len;

	len = 0;
	fd = open("textou.txt", O_RDONLY);
	line = get_next_line(fd);
	len++;
	printf("[%d]:%s\n", len, line);
	line = NULL;
	close(fd);
	return (0);
}
