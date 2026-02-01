/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpedro-s <lpedro-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 09:10:26 by lpedro-s          #+#    #+#             */
/*   Updated: 2026/02/01 15:50:02 by lpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_file_name(int argc, char **argv)
{
	if (argc == 2)
		return ("numbers.dict");
	return (argv[1]);
}

char	*ft_str_to_int(int argc, char **argv)
{
	char	*str;

	if (argc == 2)
		str = argv[1];
	else
		str = argv[2];
	while (*str)
	{
		if (*str == '0')
		{
			str++;
			continue ;
		}
		break ;
	}
	if (*str == '\0')
		str--;
	return (str);
}
