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

int	ft_file_validation(char *file)
{
	int	fd;

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

int	ft_number_validation(char *str)
{
	int	i;
	int	has_num;

	has_num = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		has_num = 1;
		i++;
	}
	while (ft_is_space(str[i]))
		i++;
	return (str[i] == ':' && has_num);
}

int	ft_number_ext_validation(char *str)
{
	int i;
	int has_text;

	i = 0;
	has_text = 0;

	while (str[i])
	{
		if (str[i] == ':')
			break ;
		i++;
	}

	i++;
	while (str[i])
	{
		if (!ft_is_space(str[i]))
			return (1);
		i++;
	}
	return (0);
}