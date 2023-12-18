/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:13:32 by niabraha          #+#    #+#             */
/*   Updated: 2023/12/18 15:46:29 by niabraha         ###   ########.fr       */
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


#include <stdlib.h> // Add missing include statement for the library that contains the malloc function
#include <unistd.h> // Add missing include statement for the library that contains the read function

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		*stash;
	int 		div;
	int			mod;
	int 		nb;

	stash = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!stash)	
		return (NULL);
	div = 0; // Fix the syntax error by assigning values to div, mod, and nb separately
	mod = 0;
	nb = 0;
	bytes_read = read(fd, stash, BUFFER_SIZE);
	printf("Bytes_read: %d\n\n", bytes_read);
	while (bytes_read >= 0)
	{
		while (stash[nb] != '\n') // Fix the syntax error by removing the address-of operator (&) from the condition
		{
			nb++;
		}
		printf("%d", nb);
		/* div = nb / BUFFER_SIZE;
		mod = nb % BUFFER_SIZE;
		printf("div: %d mod: %d nb: %d\n", div, mod, nb);
		bytes_read -= BUFFER_SIZE; */
		nb++;
		
	}
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	return (stash);
}

int main()
{
	int		fd;
	char	*line;

	fd = open("textou.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n",line);
	line = NULL;
	close(fd);
	return (0);
}
