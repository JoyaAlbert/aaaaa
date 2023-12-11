#include "get_next_line.h"

int main()
{
	int fd = open("testTexts/big.txt", O_RDONLY);
	for(int i = 0; i < 90; i++)
		printf("%s", get_next_line(fd));
	return 0;
}
