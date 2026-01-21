#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("other tests/alone.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
