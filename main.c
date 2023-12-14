/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:13:32 by niabraha          #+#    #+#             */
/*   Updated: 2023/12/14 12:26:34 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
/* 
read(int fd, void* buf (stash), size_t nbytes (Nombre de char qu'elle lit a chaque fois))

 */
int main()
{
	char* fileName = "textou.txt";

	int fd = open(fileName, O_RDWR);

	char buffer[BUFFER_SIZE];

	int bytesRead = read(fd, buffer, sizeof(buffer));

	printf("%d bytes read!\n", bytesRead);
	printf("File Contents: %s\n", buffer);

	return 0;
}