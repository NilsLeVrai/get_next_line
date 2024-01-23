/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:54:18 by niabraha          #+#    #+#             */
/*   Updated: 2024/01/23 14:02:46 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8192
# endif

# if (BUFFER_SIZE < 1 || BUFFER_SIZE > INT_MAX)
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 8192
# endif

# include <stdlib.h> //malloc, free
# include <unistd.h> //read
# include <stdio.h> //printf
# include <fcntl.h> // open dans le main

char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s1, unsigned int start, size_t len);
size_t	ft_strlen(char *s);

#endif
