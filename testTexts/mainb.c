#include "../get_next_line_bonus.h"

int	main(void)
{
	int		fd_1;
    int     fd_2;
	char	*line[1024];


    fd_1 = open("testTexts/dracula.txt", O_RDONLY);
    fd_2 = open("testTexts/quijote.txt", O_RDONLY);
	for (int i = 0; i <50; i++)
    {
		line[fd_1] = get_next_line(fd_1);
		printf("1    %s\n", line[fd_1]);
        line[fd_2] = get_next_line(fd_2);
		printf("2    %s\n", line[fd_2]);
	}

}