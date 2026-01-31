#include "header.h"

void	ft_error_input(void)
{
	write(1, "Error\n", 7);
}

void	ft_error_dict(void)
{
	write(1, "Dict Error\n", 12);
}