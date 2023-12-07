#include "get_next_line.h"

int main()
{
	int fd = open("test.txt", O_RDONLY);
	for(int i = 0; i < 2; i++)
		printf("%s", get_next_line(fd));
}
