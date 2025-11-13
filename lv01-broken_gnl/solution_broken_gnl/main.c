
#include "get_next_line.h"
#include <fcntl.h>


/* Run the program
$ cc get_next_line.c main.c -D BUFFER_SIZE=11 && ./a.out

*/

int main(void)
{
	int fd;
	char *str;
	
	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("1 NEXT_LINE = '%s'\n", str);
	str = get_next_line(fd);
	printf("2 NEXT_LINE = '%s'\n", str);
	str = get_next_line(fd);
	printf("3 NEXT_LINE = '%s'\n", str);
	str = get_next_line(fd);
	printf("4 NEXT_LINE = '%s'\n", str);
	str = get_next_line(fd);
	printf("5 NEXT_LINE = '%s'\n", str);
	str = get_next_line(fd);
	printf("6 NEXT_LINE = '%s'\n", str);
	str = get_next_line(fd);
	printf("7 NEXT_LINE = '%s'\n", str);
}