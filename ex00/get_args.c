/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 09:10:26 by lpedro-s          #+#    #+#             */
/*   Updated: 2026/02/01 11:18:50 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (str);
}
