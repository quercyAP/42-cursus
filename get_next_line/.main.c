#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.c"
#include "get_next_line_utils.c"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line == NULL)
			break ;
		free(line);
	}
	return (0);
}