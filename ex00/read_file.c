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

char *read_line(int fd) {
    char *line = malloc(1000); 
    char c;
    int i = 0;
    int bytes;
	int current_line = 0;
    
	if (!line) return (NULL);

	while ((bytes = read(fd, &c, 1)) > 0) {
		line[i++] = c;
		if (c == '\n') 
			break;
	}

	if (bytes <= 0 && i == 0) { 
		free(line);
		return (NULL);
	}

    line[i] = '\0'; 
    return (line);
}


char *ft_extract_number(char *str)
{
	char *number;
	int len;
	int index;

	if (!ft_number_validation(str))
		return ("");

	len = ft_str_len_space(str, ':');
	number = (char *)malloc((len + 1) * sizeof(char));
	index = 0;
	while (*str != ':')
	{
		if (*str >= '0' && *str <= '9')
		{
			number[index] = *str;
			index++;
		}
		str++;
	}

	number[index] = '\0';
	return (number);
}


char *ft_extract_number_ext(char *str)
{
	char *number_ext;
	int len;
	int index;
	int index_start;
	int index_end;

	if (!ft_number_ext_validation(str))
		return (NULL);

	index = 0;
	while (str[index])
	{
		if (str[index] == ':')
			break ;
		index++;
	}
	index++;
	while (str[index])
	{
		if (!ft_is_space(str[index]))
			break ;
		index ++;
	}

	index_start = index;
	index = ft_str_len(str);

	while (ft_is_space(str[index]))
		index--;

	index_end = index + 1;
	number_ext = (char *)malloc((index_end - index_start + 1) * sizeof(char));
	index = 0;
	while (index < ((index_end - index_start + 1)))
	{
		number_ext[index] = str[index_start + index];
		index++;
	}

	number_ext[index] = '\0';
	return (number_ext);
}

t_translate ft_parse_line(char *str)
{
	t_translate entry;

	if (!ft_find_char(str, ':'))
	{
		entry.number = NULL;
		return entry;
	}

	entry.number = ft_extract_number(str);
	entry.extensive = ft_extract_number_ext(str);
	entry.size = ft_str_len(entry.number);

	return (entry);
}

int ft_read_file(char *file)
{
	int fd;
	int lines;
	int total_lines;
	t_translate *translate_store;

	total_lines = count_lines(file);

	translate_store = (t_translate *)malloc((total_lines + 1) * sizeof(t_translate));

	fd = open(file, O_RDONLY);

	int j = 0;
	while (j < total_lines)
	{
		translate_store[j] = ft_parse_line(read_line(fd));
		if (translate_store[j].number[0] == '\0')
			return (0);
		if (!translate_store[j].extensive)
			return (0);
		j++;
	}

	close(fd);
	return (1);
}
