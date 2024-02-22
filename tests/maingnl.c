#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

/* int main()
{
	int fd = open("7", O_RDONLY);
	char *line = get_next_line(fd);
 	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}  
	printf("%s", line);
	free (line);
	close(fd);
} */

int main()
{
	char *line;
	int fd1 = open("10", O_RDONLY);
	int fd2 = open("11", O_RDONLY);
	int fd3 = open("12", O_RDONLY);

	line = get_next_line(fd1);
	printf("ligne1 fd1 : %s", line);
	free(line);

	line = get_next_line(fd2);
	printf("ligne2 fd1 : %s", line);
	free(line);

	line = get_next_line(fd3);
	printf("ligne1 fd2 : %s", line);
	free(line);

	line = get_next_line(fd1);
	printf("ligne2 fd2 : %s", line);
	free(line);

	line = get_next_line(fd2);
	printf("ligne1 fd3 : %s", line);
	free(line);

	line = get_next_line(fd3);
	printf("ligne2 fd3 : %s", line);
	free(line);
}
