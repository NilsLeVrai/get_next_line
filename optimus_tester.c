/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimus_tester.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <alexandre.denord@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:43:30 by adenord           #+#    #+#             */
/*   Updated: 2023/10/23 18:40:38 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int	fd;

	fd = open("test_files/test.txt", O_RDONLY);
	printf("*************\n");
	//test1
	if (strcmp("Je suis un baroudeur dans l'ame\n", get_next_line(fd)))
		printf("*test 1 : 🙅‍♂️*\n");
	else
		printf("*test 1 : ✅*\n");

	//test2
	if (strcmp("une vagabond des carpates\n", get_next_line(fd)))
		printf("*test 2 : 🙅‍♂️*\n");
	else
		printf("*test 2 : ✅*\n");

	//test3
	if (strcmp("une edelweiss des alpes\n", get_next_line(fd)))
		printf("*test 3 : 🙅‍♂️*\n");
	else
		printf("*test 3 : ✅*\n");

	//test4
	if (strcmp("\n", get_next_line(fd)))
		printf("*test 4 : 🙅‍♂️*\n");
	else
		printf("*test 4 : ✅*\n");

	//test5
	if (strcmp("une brise des pyrenees\n", get_next_line(fd)))
		printf("*test 5 : 🙅‍♂️*\n");
	else
		printf("*test 5 : ✅*\n");

	//test6
	if (strcmp("une crotte des vosges T_T\n", get_next_line(fd)))
		printf("*test 6 : 🙅‍♂️*\n");
	else
		printf("*test 6 : ✅*\n");

	//test7
	if (get_next_line(fd) != NULL)
		printf("*test 7 : 🙅‍♂️*\n");
	else
		printf("*test 7 : ✅*\n");
	printf("*************\n");

	close(fd);


	fd = open("test_files/test2.txt", O_RDONLY);
	printf("*************\n");
	//test1
	if (strcmp("Je suis la mer et le beau temps\n", get_next_line(fd)))
		printf("*test 1 : 🙅‍♂️*\n");
	else
		printf("*test 1 : ✅*\n");

	//test2
	if (strcmp("la mouette et sa fiente\n", get_next_line(fd)))
		printf("*test 2 : 🙅‍♂️*\n");
	else
		printf("*test 2 : ✅*\n");

	//test3
	if (strcmp("le mistral et l'anal\n", get_next_line(fd)))
		printf("*test 3 : 🙅‍♂️*\n");
	else
		printf("*test 3 : ✅*\n");

	//test4
	if (strcmp("la pancetta et la rosette\n", get_next_line(fd)))
		printf("*test 4 : 🙅‍♂️*\n");
	else
		printf("*test 4 : ✅*\n");

	//test5
	if (get_next_line(fd) != NULL)
		printf("*test 5 : 🙅‍♂️*\n");
	else
		printf("*test 5 : ✅*\n");
	printf("*************\n");

	close(fd);


	fd = open("test_files/test3.txt", O_RDONLY);
	printf("*************\n");
	//test1
	if (strcmp("Je suis une longue phrase sur une seule ligne enfin tu vois bien mon cousin/voisin Je suis une longue phrase sur une seule ligne enfin tu vois bien mon cousin/voisin Je suis une longue phrase sur une seule ligne enfin tu vois bien mon cousin/voisin Je suis une longue phrase sur une seule ligne enfin tu vois bien mon cousin/voisin Je suis une longue phrase sur une seule ligne enfin tu vois bien mon cousin/voisin Je suis une longue phrase sur une seule ligne enfin tu vois bien mon cousin/voisin Je suis une longue phrase sur une seule ligne enfin tu vois bien mon cousin/voisin Je suis une longue phrase sur une seule ligne enfin tu vois bien mon cousin/voisin Je suis une longue phrase sur une seule ligne enfin tu vois bien mon cousin/voisin Je suis une longue phrase sur une seule ligne enfin tu vois bien mon cousin/voisin Je suis une longue phrase sur une seule ligne enfin tu vois bien mon cousin/voisin Je suis une longue phrase sur une seule ligne enfin tu vois bien mon cousin/voisin Je suis une longue phrase sur une seule ligne enfin tu vois bien mon cousin/voisin Je suis une longue phrase sur une seule ligne enfin tu vois bien mon cousin/voisin Je suis une longue phrase sur une seule ligne enfin tu vois bien mon cousin/voisin Je suis une longue phrase sur une seule ligne enfin tu vois bien mon cousin/voisin\n", get_next_line(fd)))
		printf("*test 1 : 🙅‍♂️*\n");
	else
		printf("*test 1 : ✅*\n");

	//test2
	if (get_next_line(fd) != NULL)
		printf("*test 2 : 🙅‍♂️*\n");
	else
		printf("*test 2 : ✅*\n");
	printf("*************\n");

	close(fd);


	fd = open("test_files/test4.txt", O_RDONLY);
	printf("*************\n");
	//test1
	if (strcmp("d", get_next_line(fd)))
		printf("*test 1 : 🙅‍♂️*\n");
	else
		printf("*test 1 : ✅*\n");

	//test2
	if (get_next_line(fd) != NULL)
		printf("*test 2 : 🙅‍♂️*\n");
	else
		printf("*test 2 : ✅*\n");
	printf("*************\n");

	close(fd);


	fd = open("test_files/test5.txt", O_RDONLY);
	printf("*************\n");
	//test1
	if (get_next_line(fd) != NULL)
		printf("*test 1 : 🙅‍♂️*\n");
	else
		printf("*test 1 : ✅*\n");
	printf("*************\n");

	close(fd);


	fd = open("test_files/test6.txt", O_RDONLY);
	printf("*************\n");
	//test1
	if (strcmp("\n", get_next_line(fd)))
		printf("*test 1 : 🙅‍♂️*\n");
	else
		printf("*test 1 : ✅*\n");

	//test2
	if (strcmp("\n", get_next_line(fd)))
		printf("*test 2 : 🙅‍♂️*\n");
	else
		printf("*test 2 : ✅*\n");

	//test3
	if (strcmp("\n", get_next_line(fd)))
		printf("*test 3 : 🙅‍♂️*\n");
	else
		printf("*test 3 : ✅*\n");

	//test4
	if (strcmp("\n", get_next_line(fd)))
		printf("*test 4 : 🙅‍♂️*\n");
	else
		printf("*test 4 : ✅*\n");

	//test5
	if (get_next_line(fd) != NULL)
		printf("*test 5 : 🙅‍♂️*\n");
	else
		printf("*test 5 : ✅*\n");
	printf("*************\n");

	close(fd);

	return (0);
}
