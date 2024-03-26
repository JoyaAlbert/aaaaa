#include "../get_next_line.h"

void ft_leaks()
{
	system("leaks -q a.out");
}
int	main(void)
{
	int		fd_1;
	char	*line;
	
	atexit(ft_leaks);
	fd_1 = open("testTexts/aa.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd_1);
		if (!line)
		    break;
		printf("%s", line);
		free(line);
	}

}
