/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpedro-s <lpedro-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 09:10:26 by lpedro-s          #+#    #+#             */
/*   Updated: 2026/02/01 09:10:28 by lpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
