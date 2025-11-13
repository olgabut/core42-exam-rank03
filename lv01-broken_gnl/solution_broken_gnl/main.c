
#include "get_next_line.h"
#include <fcntl.h>


/* Run the program
$ cc get_next_line.c main.c -D BUFFER_SIZE=11 && ./a.out

*/

int main(void)
{
	int fd;
	char *str;
	int i;
	
	fd = open("files/with_nl", O_RDONLY);
	i = 1;
	while (1)
	{
		str = get_next_line(fd);
		printf("%d NEXT_LINE = '%s'\n", i, str);
		if (str == NULL)
			break;
		i++;
	}
}