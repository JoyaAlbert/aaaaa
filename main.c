#include "get_next_line.h"

int main()
{
	int fd = open("testTexts/test.txt", O_RDONLY);
	for(int i = 0; i < 15; i++)
		printf("%s", get_next_line(fd));
	system("leaks -q a.out");
	return 0;
}
