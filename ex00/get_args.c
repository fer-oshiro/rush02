char	*ft_file_name(int argc, char **argv)
{
	if (argc == 2)
		return ("numbers.dict");
	return (argv[1]);
}

int	ft_str_to_int(int argc, char **argv)
{
	char	*str;
	int		res;

	if (argc == 2)
		str = argv[1];
	else
		str = argv[2];
	res = 0;
	while (*str)
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res);
}
