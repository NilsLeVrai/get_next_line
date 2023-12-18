/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:54:15 by niabraha          #+#    #+#             */
/*   Updated: 2023/12/18 16:11:58 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next_line(char *)
{
	
}

char	*ft_current_line(char *)
{
	
}
char	*ft_join(int fd, char *)
{
	int		bytes_read;

	bytes_read = read(fd, stash, BUFFER_SIZE);
	while (bytes_read >= 0)
	{
		
	}
	
}

char	*get_next_line(int fd)
{
	char		*current_line;
	char		*next_line;
	char		*all_string;

	if (bytes_read < 0 || BUFFER_SIZE < 0)
		return (NULL);
	all_string = ft_join[fd, all_string[fd]]
	if (!all_string)	
		return (NULL);
	current_line = ft_current_line[fd, all_string[fd]];
	next_line = ft_next_line[fd, all_string[fd]];
	return (current_line);
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
