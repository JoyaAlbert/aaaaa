#include "../get_next_line.h"

int	main(void)
{
	int		fd_1;
	char	*line;


    fd_1 = open("testTexts/dracula.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd_1);
		printf("%s", line);
		if (!line)
		    break;
	}

}