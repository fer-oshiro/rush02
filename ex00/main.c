/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpedro-s <lpedro-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 10:25:59 by fsayuri-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/02/01 09:10:00 by fsayuri-         ###   ########.fr       */
=======
/*   Updated: 2026/02/01 09:11:35 by lpedro-s         ###   ########.fr       */
>>>>>>> a3e1b8a36087febbac261af0485371795e99789b
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	char	*file;
	int		num;

	if (!ft_arg_validation(argc, argv))
	{
		ft_error_input();
		return (0);
	}
	file = ft_file_name(argc, argv);
	num = ft_str_to_int(argc, argv);
	if (!ft_read_file(file))
	{
		ft_error_dict();
		return (0);
	}
}
