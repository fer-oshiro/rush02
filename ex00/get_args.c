/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 09:10:26 by lpedro-s          #+#    #+#             */
/*   Updated: 2026/02/01 12:12:12 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_file_name(int argc, char **argv)
{
	if (argc == 2)
		return ("numbers.dict");
	return (argv[1]);
}

#include <stdio.h> 
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
