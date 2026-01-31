#include "header.h"

int count_lines(char *file)
{
	char c;
	int bytes;
	int current_line;
	int fd;

	fd = open(file, O_RDONLY);
	current_line = 0;
	while ((bytes = read(fd, &c, 1)) > 0) {
		if (c == '\n')
			current_line++;
	}
	close(fd);
	return (current_line);
}

char *read_line(int fd, int row) {
    char *line = malloc(1000); 
    char c;
    int i = 0;
    int bytes;
	int current_line = 0;
    
	if (!line) return (NULL);

	while ((bytes = read(fd, &c, 1)) > 0) {
		if (row == current_line)
		{
			line[i++] = c;
			if (c == '\n') 
				break;
		}
		if (c == '\n')
			current_line++;
	}

	if (bytes <= 0 && i == 0) { 
		free(line);
		return (NULL);
	}

    line[i] = '\0'; 
    return (line);
}

void ft_read_file(char *file)
{
	int fd;
	int lines;
	int i;
	

	i = count_lines(file);

	fd = open(file, O_RDONLY);
	printf("%s\n", read_line(fd, 5));
	close(fd);


	printf("%i", i);
}