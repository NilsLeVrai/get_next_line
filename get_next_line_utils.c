/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:54:10 by niabraha          #+#    #+#             */
/*   Updated: 2024/01/10 15:39:42 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char    *ft_substr(const char *s, unsigned int start, size_t len)
{
        size_t  i;
        size_t  len_s;
        char    *p;

        i = 0;
        if (!s)
                return (NULL);
        len_s = ft_strlen(s);
        if (len > len_s - start)
                len = len_s - start;
        p = (char *)malloc(sizeof(char) * (len + 1));
        if (!p)
                return (NULL);
        while (s[start] && i < len)
                p[i++] = s[start++];
        p[i] = '\0';
        return (p);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	size_s1;
	size_t	size_s2;
	char	*p;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	p = (char *) malloc (sizeof(char) * (size_s1 + size_s2 + 1));
	if (!p)
		return (NULL);
	while (*s1)
		p[i++] = *s1++;
	while (*s2)
		p[i++] = *s2++;
	p[i] = '\0';
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int		i;
	unsigned char		char_find;
	size_t				len;

	char_find = (unsigned char) c;
	i = 0;
	len = ft_strlen(s);
	while (i <= (unsigned int) len)
	{
		if (s[i] == char_find)
			return ((char *) &s[i]);
		i++;
	}
	return (NULL);
}
/* char    *ft_strchr(const char *s, int c)
{
    if ((unsigned char)c == '\0' && *s == '\0')
        return ((char *)s);
    while (*s)
    {
        if (*s == (unsigned char)c)
            return ((char *)s);
        if (*(s + 1) == (unsigned char)c)
            return ((char *)s + 1);
        s++;
    }
    return (NULL);
} */

