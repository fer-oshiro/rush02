/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpedro-s <lpedro-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 09:09:29 by lpedro-s          #+#    #+#             */
/*   Updated: 2026/02/01 11:30:31 by lpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_error_input(void)
{
	write(1, "Error\n", 6);
}

void	ft_error_dict(void)
{
	write(1, "Dict Error\n", 11);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (0);
}
