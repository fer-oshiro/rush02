#include "header.h"

int	ft_num_validation(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int ft_file_validation(char *file)
{
	int fd;

    fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	ft_arg_validation(int argc, char **argv)
{
	if (argc == 1 || argc > 3)
		return (0);

	if (argc == 2)
		return (ft_num_validation(argv[1]));

	if (argc == 3)
	{
		return (ft_file_validation(argv[1]) && ft_num_validation(argv[2]));
	}

	return (1);
}

